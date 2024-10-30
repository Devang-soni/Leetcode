/*
You may recall that an array arr is a mountain array if and only if:

arr.length >= 3
There exists some index i (0-indexed) with 0 < i < arr.length - 1 such that:
arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
Given an integer array nums​​​, return the minimum number of elements to remove to make nums​​​ a mountain array.

 

Example 1:

Input: nums = [1,3,1]
Output: 0
Explanation: The array itself is a mountain array so we do not need to remove any elements.
Example 2:

Input: nums = [2,1,1,5,6,2,3,1]
Output: 3
Explanation: One solution is to remove the elements at indices 0, 1, and 5, making the array nums = [1,5,6,3,1].
*/

class Solution {
public:
    int lis(int i, vector<int>& nums, vector<int>& dp) {
        if (dp[i] != -1)
            return dp[i];
        int maxi = 1;
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j]) {
                maxi = max(maxi, lis(j, nums, dp) + 1);
            }
        }
        return dp[i] = maxi;
    }
    int lds(int i, vector<int>& nums, vector<int>& dp) {
        if (dp[i] != -1)
            return dp[i];
        int maxi = 1;
        for (int j = i + 1; j < nums.size(); j++) {
            if (nums[i] > nums[j]) {
                maxi = max(maxi, lds(j, nums, dp) + 1);
            }
        }
        return dp[i] = maxi;
    }

    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        if (n < 3)
            return 0;
        vector<int> lisOfAllIndices(n, -1);
        vector<int> ldsOfAllIndices(n, -1);

        for (int i = 0; i < n; i++) 
        lis(i, nums, lisOfAllIndices);
        
        for (int i = n - 1; i >= 0; i--) 
        lds(i, nums, ldsOfAllIndices);
        

        int maxi = 0;
        for (int i = 1; i < n - 1; i++) {
            if (lisOfAllIndices[i] > 1 && ldsOfAllIndices[i] > 1) { 
                maxi = max(maxi, lisOfAllIndices[i] + ldsOfAllIndices[i] - 1);
            }
        }
        return n - maxi;
    }
};
