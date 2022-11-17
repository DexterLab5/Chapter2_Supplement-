#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INT_SIZE sizeof(int)         // Size of int in bytes
#define INT_BITS INT_SIZE * 8 - 1    // Size of int in bits - 1

unsigned hexadecimal_to_decimal(unsigned x) {
    // convert unsigned to string
    char hex[100];
    sprintf(hex, "%i", x);
    unsigned decimal = 0;
    int base = 1, length = strlen(hex);
    // Get the last digit and mulitply it by base, base gets multiplied by 16 on every loop
    for (int i = --length; i >= 0; i--) {
        decimal += (hex[i] - 48) * base;
        base *= 16;
    }
    return decimal;
}

char* decimal_to_hexadecimal(unsigned x) {
    char* hexadecimal = malloc(sizeof(char)*100);
    strcpy(hexadecimal,"");
    int remainder = 0, i = 0;
    // Divide x by 16 and store the remainder. Then convert the remainder to a number or charcter using asii and store it in a string
    while (x > 0) {
        remainder = x % 16;
        if (remainder < 10) {
            hexadecimal[i++] = 48 + remainder;
        }
        else {
            hexadecimal[i++] = 55 + remainder;
        }
        x /= 16;
    }
    hexadecimal[i] = '\0';
    // Reverse it
    strrev(hexadecimal);
    return hexadecimal;
}

void rotate_left(unsigned int x, unsigned char n) {
    x = hexadecimal_to_decimal(x);
    
    // Loot till n is 0
    while (n--) {
        // store the first bit of x
        unsigned droppedMSB = (x >> INT_BITS) & 1;
        // shift left x 1 time and insert it's dropped bit at the back
        x = (x << 1) | droppedMSB;
    }
    char* hexadecimal_x = decimal_to_hexadecimal(x);
    printf("%s",hexadecimal_x);
}

int main(void) {
    unsigned x = 12345678;
    unsigned char n = 2;
    rotate_left(x,n);
}