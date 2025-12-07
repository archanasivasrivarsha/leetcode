#include <string.h>

int strStr(char * haystack, char * needle){
    if (!needle || !*needle) return 0; // empty needle

    int hLen = strlen(haystack);
    int nLen = strlen(needle);

    if (nLen > hLen) return -1;

    for (int i = 0; i <= hLen - nLen; i++) {
        int j;
        for (j = 0; j < nLen; j++) {
            if (haystack[i + j] != needle[j]) break;
        }
        if (j == nLen) return i; // found
    }

    return -1; // not found
}
