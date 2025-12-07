int removeElement(int* nums, int numsSize, int val) {
    int i = 0; // slow pointer
    for (int j = 0; j < numsSize; j++) { // fast pointer
        if (nums[j] != val) {
            nums[i] = nums[j];
            i++;
        }
    }
    return i; // new length
}
