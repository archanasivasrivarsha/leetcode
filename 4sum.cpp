#include <stdlib.h>
#include <stdio.h>

int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

// Helper function to add quadruplet to the results
void addQuad(int** res, int* returnSize, int* quad) {
    res[*returnSize] = (int*)malloc(4 * sizeof(int));
    for (int i = 0; i < 4; i++) {
        res[*returnSize][i] = quad[i];
    }
    (*returnSize)++;
}

int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes){
    *returnSize = 0;
    if (numsSize < 4) return NULL;

    qsort(nums, numsSize, sizeof(int), cmp);

    int** res = (int**)malloc(1000 * sizeof(int*)); // Adjust size as needed
    *returnColumnSizes = (int*)malloc(1000 * sizeof(int));

    for (int i = 0; i < numsSize - 3; i++) {
        if (i > 0 && nums[i] == nums[i-1]) continue; // skip duplicates
        for (int j = i + 1; j < numsSize - 2; j++) {
            if (j > i + 1 && nums[j] == nums[j-1]) continue; // skip duplicates
            int left = j + 1, right = numsSize - 1;
            while (left < right) {
                long sum = (long)nums[i] + nums[j] + nums[left] + nums[right];
                if (sum == target) {
                    int quad[4] = {nums[i], nums[j], nums[left], nums[right]};
                    addQuad(res, returnSize, quad);
                    (*returnColumnSizes)[*returnSize - 1] = 4;

                    // skip duplicates
                    while (left < right && nums[left] == nums[left+1]) left++;
                    while (left < right && nums[right] == nums[right-1]) right--;
                    left++;
                    right--;
                } else if (sum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }
    }

    return res;
}
