#include <stdio.h>
#include <stdlib.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int total = nums1Size + nums2Size;
    int *merged = (int*)malloc(total * sizeof(int));
    int i = 0, j = 0, k = 0;

    // Merge two sorted arrays
    while(i < nums1Size && j < nums2Size){
        if(nums1[i] < nums2[j]){
            merged[k++] = nums1[i++];
        } else {
            merged[k++] = nums2[j++];
        }
    }

    // Copy remaining elements
    while(i < nums1Size) merged[k++] = nums1[i++];
    while(j < nums2Size) merged[k++] = nums2[j++];

    double median;
    if(total % 2 == 0){
        median = (merged[total/2 - 1] + merged[total/2]) / 2.0;
    } else {
        median = merged[total/2];
    }

    free(merged);
    return median;
}

