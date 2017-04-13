#include <stdio.h>
#include <stdlib.h>

int check(char *value) {
    value[0] = 99;
    value[1] = 115;
    value[2] = 50;
    value[3] = 49;
    value[4] = 48;
    value[5] = 55;
    value[6] = 123;
    value[7] = 119;
    value[8] = 105;
    value[9] = 110;
    value[10] = 110;
    value[11] = 105;
    value[12] = 110;
    value[13] = 103;
    value[14] = 95;
    value[15] = 116;
    value[16] = 104;
    value[17] = 105;
    value[18] = 115;
    value[19] = 95;
    value[20] = 105;
    value[21] = 115;
    value[22] = 95;
    value[23] = 103;
    value[24] = 48;
    value[25] = 48;
    value[26] = 100;
    value[27] = 125;
    return 1;
}

int main()
{
	char *value;
	value = (char *)malloc(sizeof(char) * 30);
    if(check(value)) {
        printf("Flag: %s\n", value);
    }
    else {
        puts("Incorrect flag");
    }
}
