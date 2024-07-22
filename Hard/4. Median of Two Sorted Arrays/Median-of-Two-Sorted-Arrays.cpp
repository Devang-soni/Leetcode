/*
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

 

Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        vector<int>MergeArray(n+m);
        int i=0, j=0, k=0;

        while(i<m && j<n){
            if(nums1[i] < nums2[j]){
                MergeArray[k++] = nums1[i++];
            }
            else{
                MergeArray[k++] = nums2[j++];
            }
        }

        while(i < m){
            MergeArray[k++] = nums1[i++];
        }
        while(j < n){
            MergeArray[k++] = nums2[j++];
        }

        if((m+n) % 2 == 0){
            int mid1 = MergeArray[(m+n)/2];
            int mid2 = MergeArray[(m+n)/2-1];

            return (static_cast<double> (mid1 + mid2) / 2.0);

        }
        else{
            return static_cast<double>(MergeArray[(m+n) / 2]);
        }

    }
};
