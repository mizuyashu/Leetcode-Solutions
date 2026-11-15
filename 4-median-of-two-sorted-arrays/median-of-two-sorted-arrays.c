double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int total = nums1Size + nums2Size;
    int i = 0;
    int j = 0;
    int prev = 0;
    int cur =0;


    for (int k =0; k <= total/2; k++){

        prev = cur;

        // just checks which array is smaller at the current iteration of the loop, and that i, or j has not exceeded its array size
        if (i < nums1Size && (j >= nums2Size || nums1[i] <= nums2[j])) {
            cur = nums1[i++];
        } else {
            cur = nums2[j++];
        }

    }

    // here you have the median unless its even, so check that and if its even do avg of prev and curr
    if (total %2 ==1){
        return cur;
    } else {
        return (prev + cur)/2.0;
    }
}