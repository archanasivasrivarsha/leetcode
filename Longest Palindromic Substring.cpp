#include <string.h>
#include <stdlib.h>

// Helper function to expand around the center
int expandAroundCenter(char* s, int left, int right) {
    int len = strlen(s);
    while (left >= 0 && right < len && s[left] == s[right]) {
        left--;
        right++;
    }
    return right - left - 1; // length of palindrome
}

char* longestPalindrome(char* s) {
    int start = 0, end = 0;
    int len = strlen(s);

    for (int i = 0; i < len; i++) {
        int len1 = expandAroundCenter(s, i, i);     // odd length
        int len2 = expandAroundCenter(s, i, i + 1); // even length
        int maxLen = len1 > len2 ? len1 : len2;
        if (maxLen > end - start) {
            start = i - (maxLen - 1) / 2;
            end = i + maxLen / 2;
        }
    }

    int resultLen = end - start + 1;
    char* result = (char*)malloc(resultLen + 1);
    strncpy(result, s + start, resultLen);
    result[resultLen] = '\0';
    return result;
}

