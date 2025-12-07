#include <stdbool.h>
#include <limits.h>

bool isPalindrome(int x){
    // Negative numbers are not palindrome
    if(x < 0) return false;
    // Numbers ending with 0 (except 0 itself) are not palindrome
    if(x != 0 && x % 10 == 0) return false;

    int reversed = 0;
    int original = x;

    while(x > 0){
        int pop = x % 10;
        x /= 10;

        // Check overflow
        if(reversed > (INT_MAX - pop)/10) return false;

        reversed = reversed * 10 + pop;
    }

    return reversed == original;
}

