#include <limits.h>
#include <stdlib.h>

int divide(int dividend, int divisor) {
    // Handle overflow case
    if (dividend == INT_MIN && divisor == -1) {
        return INT_MAX;
    }

    // Determine the sign of the result
    int negative = (dividend < 0) ^ (divisor < 0);

    // Convert to long long to handle overflow and take absolute values
    long long dvd = llabs((long long)dividend);
    long long dvs = llabs((long long)divisor);
    long long quotient = 0;

    // Subtract multiples of divisor from dividend
    while (dvd >= dvs) {
        long long temp = dvs, multiple = 1;
        while (dvd >= (temp << 1)) {
            temp <<= 1;
            multiple <<= 1;
        }
        dvd -= temp;
        quotient += multiple;
    }

    return negative ? -quotient : quotient;
}

