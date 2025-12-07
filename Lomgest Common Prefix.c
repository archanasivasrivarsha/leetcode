#include <stdlib.h>
#include <string.h>

char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize == 0) return "";

    int prefixLen = strlen(strs[0]);

    for (int i = 1; i < strsSize; i++) {
        int j = 0;
        while (j < prefixLen && strs[i][j] && strs[0][j] == strs[i][j]) {
            j++;
        }
        prefixLen = j;
        if (prefixLen == 0) return "";
    }

    char* prefix = (char*)malloc(prefixLen + 1);
    strncpy(prefix, strs[0], prefixLen);
    prefix[prefixLen] = '\0';
    return prefix;
}
