#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* decimal_to_binary(int x) {
    char* binaryNum = malloc(sizeof(char)*32);
    // Deviding x by 2 till it's zero and collecting the remainders in a string
    int i = 0;
    if (x == 0) {
        strcpy(binaryNum, "0");
        return binaryNum;
    }
    while (x > 0) {
        binaryNum[i] = (x % 2) + 48;
        x /= 2;
        i++;
    }
    binaryNum[i] = '\0';
    // reverse it
    strrev(binaryNum);
    return binaryNum;
}

int main(void) {
    int x = 0;
    printf("Enter x: ");
    scanf("%i", &x);
    // Get the binary representation of x
    char* binaryNum = decimal_to_binary(x);
    printf("Reversed binaryNum = %s\n", binaryNum);
    // Iterate through the first byte of binaryNum, which is most-significant and check every bit. If i is equal to length
    // break the loop
    int len = strlen(binaryNum);
    for (int i = 0; i < 8; i++) {
        if (i == len) {
            break;
        }
        if (binaryNum[i] == '0') {
            printf("return 1\n");
            return 1;
        }
    }
    printf("return 0\n");
    return 0;
}