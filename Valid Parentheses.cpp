#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

bool isValid(char * s){
    int len = strlen(s);
    if (len % 2 != 0) return false; // odd length cannot be valid

    char* stack = (char*)malloc(len);
    int top = -1;

    for (int i = 0; i < len; i++) {
        char c = s[i];
        if (c == '(' || c == '{' || c == '[') {
            stack[++top] = c; // push
        } else {
            if (top == -1) {
                free(stack);
                return false; // unmatched closing
            }
            char last = stack[top--]; // pop
            if ((c == ')' && last != '(') ||
                (c == '}' && last != '{') ||
                (c == ']' && last != '[')) {
                free(stack);
                return false; // mismatch
            }
        }
    }

    bool valid = (top == -1);
    free(stack);
    return valid;
}
