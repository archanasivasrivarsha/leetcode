#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void backtrack(char **res, int *returnSize, char *digits, int index, char *combo, char **map) {
    if(digits[index] == '\0') {
        combo[index] = '\0';
        res[*returnSize] = strdup(combo);  // copy combo to result
        (*returnSize)++;
        return;
    }

    int digit = digits[index] - '2';
    char *letters = map[digit];

    for(int i = 0; letters[i] != '\0'; i++) {
        combo[index] = letters[i];
        backtrack(res, returnSize, digits, index + 1, combo, map);
    }
}

char ** letterCombinations(char * digits, int* returnSize){
    *returnSize = 0;
    int len = strlen(digits);
    if(len == 0) return NULL;

    // Mapping digits to letters
    char *map[8] = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

    int maxComb = 1;
    for(int i = 0; i < len; i++) {
        int digit = digits[i] - '2';
        int numLetters = strlen(map[digit]);
        maxComb *= numLetters;
    }

    char **res = (char**)malloc(maxComb * sizeof(char*));
    char *combo = (char*)malloc((len + 1) * sizeof(char));

    backtrack(res, returnSize, digits, 0, combo, map);

    free(combo);
    return res;
}

