#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
	char message[1000], server_reply[2000];
	char ip1[16], ip2[16];
	int letter[26];
	FILE *fp;
	int sock1, sock2, total = 0;
	struct sockaddr_in client1, client2;
    

    //Count lines
	if (argc == 1)
	{
		printf("No file to read\n");
		return -1;
	}
    fp = fopen(argv[1],"r");
    if(fp == NULL){ 
        printf("Could not open file\n"); 
        return -1; 
    }
    while(!feof(fp)){
        fgets(message, 200, fp);
        total++;
    }
    fclose(fp);
    printf("File has %d lines\n", total);
	

    //Read ip
    fp = fopen("workers.conf","r");
    if(fp == NULL){ 
        printf("Could not open file\n"); 
        return -1; 
    }
    fgets(ip1, 16, fp);
    fgets(ip2, 16, fp);
    fclose(fp);
	printf("Ip got\n");

    //Create socket
    sock1 = socket(AF_INET, SOCK_STREAM, 0);
    sock2 = socket(AF_INET, SOCK_STREAM, 0);
    if (sock1 == -1 || sock2 == -1) {
        printf("Could not create socket\n");
        return -1;
    }
    printf("Socket created\n");

    //Set client
    client1.sin_addr.s_addr = inet_addr(ip1);
    client1.sin_family = AF_INET;
    client1.sin_port = htons(12345);
    client2.sin_addr.s_addr = inet_addr(ip2);
    client2.sin_family = AF_INET;
    client2.sin_port = htons(12345);

    //Connect to remote client
    while(1){
	    if (connect(sock1, (struct sockaddr *)&client1, sizeof(client1)) >=0) {
	        break;
	    }
	}
    while(1){
	    if (connect(sock2, (struct sockaddr *)&client2, sizeof(client2)) >= 0) {
	        break;
	    }
	}
    printf("Connected\n");

    //Initialize
    memset(letter, 0, 26 * sizeof(int));
	memset(message, 0, 1000);

	//Send message
	int * msg = (int *)message;
	int i, length;
	msg[0] = 0;
	msg[1] = total / 2;
	strcpy(&message[8], argv[1]);
    length = 2 + (strlen(argv[1]) - 1) / 4 + 1;
    for(i = 0; i < length; i++){
        msg[i] = htonl(msg[i]);
    }
    send(sock1, message, length * 4, 0);
    msg[0] = msg[1];
	msg[1] = htonl(total);
	send(sock2, message, length * 4, 0);

	//Receive message
    int * reply = (int *)server_reply;
    while(1){
		if(recv(sock1, server_reply, 2000, 0) == 104){
			for(i = 0; i < 26;i++){
        		letter[i] += ntohl(reply[i]);
			}
			break;
		}
    }
    while(1){
		if(recv(sock2, server_reply, 2000, 0) == 104){
			for(i = 0; i < 26;i++){
        		letter[i] += ntohl(reply[i]);
			}
			break;
		}
    }
    
    //Print results
    printf("Show result:\n");
    for(i = 0; i < 26; i++){
        printf("%c %d\n", i + 'a', letter[i]);
    }

	return 0;
}