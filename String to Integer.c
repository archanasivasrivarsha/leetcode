#include <limits.h>
#include <ctype.h>

int myAtoi(char *str) {
    int i = 0;
    long result = 0;
    int sign = 1;

    // Skip leading whitespaces
    while (str[i] && isspace(str[i])) {
        i++;
    }

    // Check optional sign
    if (str[i] == '+' || str[i] == '-') {
        sign = (str[i] == '-') ? -1 : 1;
        i++;
    }

    // Convert digits to integer
    while (str[i] && isdigit(str[i])) {
        result = result * 10 + (str[i] - '0');

        // Check overflow
        if (sign * result > INT_MAX) return INT_MAX;
        if (sign * result < INT_MIN) return INT_MIN;

        i++;
    }

    return (int)(sign * result);
}
