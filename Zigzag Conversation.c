#include <stdlib.h>
#include <string.h>

char* convert(char* s, int numRows) {
    if (numRows == 1 || numRows >= strlen(s)) {
        // No zigzag needed
        char* res = (char*)malloc(strlen(s) + 1);
        strcpy(res, s);
        return res;
    }

    int len = strlen(s);
    char* res = (char*)malloc(len + 1);
    int idx = 0;

    for (int row = 0; row < numRows; row++) {
        int step1 = (numRows - row - 1) * 2;
        int step2 = row * 2;
        int i = row;
        int toggle = 0;

        while (i < len) {
            res[idx++] = s[i];
            if (row == 0 || row == numRows - 1) {
                i += (numRows - 1) * 2; // first and last rows
            } else {
                i += toggle ? step2 : step1;
                toggle = !toggle;
            }
        }
    }

    res[idx] = '\0';
    return res;
}

