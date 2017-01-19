// Source : https://leetcode.com/problems/median-of-two-sorted-arrays/
// Author : daming
// Date   : 2017-01-19

/*************************************************************************************** 
 *
 * There are two sorted arrays nums1 and nums2 of size m and n respectively.
 * 
 * Find the median of the two sorted arrays. The overall run time complexity should be 
 * O(log (m+n)).
 * 
 * Example 1:
 * 
 * nums1 = [1, 3]
 * nums2 = [2]
 * 
 * The median is 2.0
 * 
 * Example 2:
 * 
 * nums1 = [1, 2]
 * nums2 = [3, 4]
 * 
 * The median is (2 + 3)/2 = 2.5
 * 
 ***************************************************************************************/

inline int min(int m, int n){
    return n<m?n:m;
}
int getKMin(int s1[], int n1, int s2[], int n2, int k){
    int i,j;
    
    if (n1 > n2)
        return getKMin(s2, n2, s1, n1, k);
    if (n1 == 0)
        return s2[k-1];
    if (k == 1)
        return min(s1[0], s2[0]);
    i = min(n1, k/2);
    j = min(n2, k/2);
    // 如果s2前j个数小于s1，那么，这j个数肯定是在排在前面的，那么可以不考虑这些了
    if(s1[i-1] > s2[j-1])
        return getKMin(s1, n1, s2+j, n2-j, k-j);
    else
        return getKMin(s1+i, n1-i, s2, n2, k-i);
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int len = nums1Size+nums2Size;
    if (len%2 == 0){
        return (getKMin(nums1, nums1Size, nums2, nums2Size, len/2)+getKMin(nums1, nums1Size, nums2, nums2Size, len/2+1))/2.0;
    } else {
        return getKMin(nums1, nums1Size, nums2, nums2Size, len/2+1);
    }
}
