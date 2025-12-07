int removeDuplicates(int* nums, int numsSize) {
    if (numsSize == 0) return 0;

    int i = 0; // slow pointer
    for (int j = 1; j < numsSize; j++) { // fast pointer
        if (nums[j] != nums[i]) {
            i++;
            nums[i] = nums[j];
        }
    }
    return i + 1; // new length
}
