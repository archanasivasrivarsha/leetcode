#include <stdlib.h>

int findBound(int* nums, int numsSize, int target, int isFirst) {
    int left = 0, right = numsSize - 1;
    int bound = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            bound = mid;
            if (isFirst)
                right = mid - 1; // search left half
            else
                left = mid + 1;  // search right half
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return bound;
}

int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize = 2;
    int* result = (int*)malloc(2 * sizeof(int));

    result[0] = findBound(nums, numsSize, target, 1); // first position
    result[1] = findBound(nums, numsSize, target, 0); // last position

    return result;
}
