#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Helper function to generate the next term from the current term
char* nextTerm(const char* s) {
    int len = strlen(s);
    char* result = (char*)malloc(2 * len * sizeof(char) + 1); // worst case
    int pos = 0;
    int i = 0;

    while (i < len) {
        char c = s[i];
        int count = 1;
        while (i + 1 < len && s[i + 1] == c) {
            count++;
            i++;
        }
        // append count and digit
        pos += sprintf(result + pos, "%d%c", count, c);
        i++;
    }
    result[pos] = '\0';
    return result;
}

char* countAndSay(int n){
    if (n <= 0) return NULL;

    char* term = (char*)malloc(2 * sizeof(char));
    strcpy(term, "1"); // base case

    for (int i = 2; i <= n; i++) {
        char* next = nextTerm(term);
        free(term); // free previous term
        term = next;
    }

    return term;
}

// Example usage:
// int main() {
//     int n = 4;
//     char* res = countAndSay(n);
//     printf("%s\n", res); // Output: 1211
//     free(res);
//     return 0;
// }
