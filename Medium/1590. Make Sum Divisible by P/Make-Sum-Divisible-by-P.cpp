/*
Given an array of positive integers nums, remove the smallest subarray (possibly empty) such that the sum of the remaining elements is divisible by p. It is not allowed to remove the whole array.

Return the length of the smallest subarray that you need to remove, or -1 if it's impossible.

A subarray is defined as a contiguous block of elements in the array.

 

Example 1:

Input: nums = [3,1,4,2], p = 6
Output: 1
Explanation: The sum of the elements in nums is 10, which is not divisible by 6. We can remove the subarray [4], and the sum of the remaining elements is 6, which is divisible by 6.
Example 2:

Input: nums = [6,3,5,2], p = 9
Output: 2
Explanation: We cannot remove a single element to get a sum divisible by 9. The best way is to remove the subarray [5,2], leaving us with [6,3] with sum 9.
Example 3:

Input: nums = [1,2,3], p = 3
Output: 0
Explanation: Here the sum is 6. which is already divisible by 3. Thus we do not need to remove anything.

*/

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long totalSum = 0;  // Use long long to avoid overflow
        for (int num : nums) {
            totalSum += num;
        }
        int remainder = totalSum % p;

        // If the total sum is already divisible by p, return 0
        if (remainder == 0) {
            return 0;
        }

        return findSmallestSubarray(nums, p, remainder);
    }

private:
    int findSmallestSubarray(vector<int>& nums, int p, int remainder) {
        long long prefixSum = 0;  // Use long long to avoid overflow
        int minLength = nums.size();
        unordered_map<int, int> prefixMap;
        prefixMap[0] = -1;  // Initial condition for no subarray

        for (int i = 0; i < nums.size(); i++) {
            prefixSum += nums[i];
            int targetRemainder = (prefixSum % p - remainder + p) % p;

            if (prefixMap.find(targetRemainder) != prefixMap.end()) {
                minLength = min(minLength, i - prefixMap[targetRemainder]);
            }

            prefixMap[prefixSum % p] = i;
        }

        return minLength < nums.size() ? minLength : -1;
    }
};
