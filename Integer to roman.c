#include <stdlib.h>
#include <string.h>

char* intToRoman(int num) {
    // Arrays of values and corresponding Roman numerals
    int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    char* symbols[] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};

    char* res = (char*)malloc(20); // max length for 3999 is 15, extra space for safety
    res[0] = '\0';
    int i = 0;

    while (num > 0) {
        while (num >= values[i]) {
            strcat(res, symbols[i]);
            num -= values[i];
        }
        i++;
    }

    return res;
}
