#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    int s, cs;
    struct sockaddr_in server, client;
    char message[2000];
     
    // Create socket
    if ((s = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Could not create socket");
		return -1;
    }
    printf("Socket created");

    // Prepare the sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(12345);

    // Bind
    if (bind(s, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("Bind failed. Error");
        return -1;
    }
    printf("Bind done");

    // Listen
    listen(s, 128);

    // Accept and incoming connection
    printf("Waiting for incoming connections...\n");

    // Accept connection from server
    int c = sizeof(struct sockaddr_in);
    while(1){
        if ((cs = accept(s, (struct sockaddr *)&client, (socklen_t *)&c)) < 0) {
            perror("accept failed");
        }
        else{
            break;
        }
    }
    printf("Connection accepted");

    // Receive a message from server
    int * msg  = (int *)message;
    int i, startline, endline, msg_len = 0;
    while(1){
        if((msg_len = recv(cs, message, sizeof(message), 0)) > 0){
            break;
        }
        else{
            printf("recv failed");
        }

    }

    //Process message
    startline = ntohl(msg[0]);
    endline = ntohl(msg[1]);
    msg_len = (msg_len - 1) / 4 + 1;
    for(i = 2; i < msg_len; i++){
        msg[i - 2] = ntohl(msg[i]);
    }
    printf("Get startline %d, endline %d, filename %s\n", startline, endline, message);

    //Open file
    FILE *fp;
    fp = fopen(message, "r");
    if(fp == NULL){ 
        printf("Could not open file\n"); 
        return -1; 
    }

    //Count letter number
    int letter[26], length;
    char current;
    memset(letter, 0, 26 * sizeof(int));

    for(i = 0; i < startline; i++){
        fgets(message, 200, fp);
    }

    while(startline < endline && !feof(fp)){
        fgets(message, 200, fp);
        length = strlen(message);

        for(i = 0; i < length; i++){
            current = message[i];
            if(current >= 'a' && current <= 'z'){
                letter[current - 'a']++;
            }

            if(current >= 'A' && current <= 'Z'){
                letter[current - 'A']++;
            }
        }

        startline++;
    }
    fclose(fp);

    // //Print results
    // for(i = 0; i < 26; i++){
    //     printf("%c %d\n", i + 'a', letter[i]);
    // }

    //Send message back to server
    memset(message, 0, 2000);
    for(i = 0; i < 26; i++){
        msg[i] = htonl(letter[i]);
    }
    write(cs, message, 104);

	return 0;
}