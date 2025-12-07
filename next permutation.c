#include <stdlib.h>

// Swap two integers
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Reverse the subarray nums[start..end]
void reverse(int* nums, int start, int end) {
    while (start < end) {
        swap(&nums[start], &nums[end]);
        start++;
        end--;
    }
}

void nextPermutation(int* nums, int numsSize){
    int i = numsSize - 2;

    // Find first decreasing element
    while (i >= 0 && nums[i] >= nums[i + 1]) i--;

    if (i >= 0) {
        int j = numsSize - 1;
        // Find element just larger than nums[i]
        while (nums[j] <= nums[i]) j--;
        swap(&nums[i], &nums[j]);
    }

    // Reverse the elements after index i
    reverse(nums, i + 1, numsSize - 1);
}

