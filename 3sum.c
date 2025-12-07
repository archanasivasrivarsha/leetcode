#include <stdlib.h>

// Compare function for qsort
int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

// Add a triplet to the result
void addTriplet(int*** res, int* returnSize, int* returnColumnSizes, int a, int b, int c) {
    (*res)[*returnSize] = (int*)malloc(3 * sizeof(int));
    (*res)[*returnSize][0] = a;
    (*res)[*returnSize][1] = b;
    (*res)[*returnSize][2] = c;
    returnColumnSizes[*returnSize] = 3;
    (*returnSize)++;
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    if (numsSize < 3) return NULL;

    qsort(nums, numsSize, sizeof(int), cmp);

    int maxResults = 1000;
    int** res = (int**)malloc(maxResults * sizeof(int*));
    *returnColumnSizes = (int*)malloc(maxResults * sizeof(int));

    for (int i = 0; i < numsSize - 2; i++) {
        if (i > 0 && nums[i] == nums[i-1]) continue; // skip duplicates

        int left = i + 1, right = numsSize - 1;

        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];

            if (sum == 0) {
                addTriplet(&res, returnSize, *returnColumnSizes, nums[i], nums[left], nums[right]);

                while (left < right && nums[left] == nums[left+1]) left++;  // skip duplicates
                while (left < right && nums[right] == nums[right-1]) right--; // skip duplicates

                left++;
                right--;
            } else if (sum < 0) {
                left++;
            } else {
                right--;
            }
        }
    }

    return res;
}
