/*
Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k odd numbers on it.
Return the number of nice sub-arrays.

Example 1:

Input: nums = [1,1,2,1,1], k = 3
Output: 2
Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].
Example 2:

Input: nums = [2,4,6], k = 1
Output: 0
Explanation: There are no odd numbers in the array.
Example 3:

Input: nums = [2,2,2,1,2,2,1,2,2,2], k = 2
Output: 16
*/

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int ans = 0, oddCount = 0, prevCount = 0;
        int low = 0, high = 0;
        while (high < nums.size()) {
            if (nums[high] % 2 != 0) {
                oddCount++;
                prevCount = 0;
            }
            while (oddCount == k) {
                prevCount++;
                if (low < nums.size() && nums[low] % 2 == 1) {
                    oddCount--;
                }
                low++;
            }
            ans += prevCount;
            high++;
        }
        return ans;
    }
};