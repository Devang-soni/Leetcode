/*
You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.

Return the single element that appears only once.

Your solution must run in O(log n) time and O(1) space.

 

Example 1:

Input: nums = [1,1,2,3,3,4,4,8,8]
Output: 2
Example 2:

Input: nums = [3,3,7,7,10,11,11]
Output: 10
*/

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        
        for(int i=0; i<n; i++){
            if (i == 0) {
            if (nums[i] != nums[i + 1])
                return nums[i];
        }
        //Check for last index:
        else if (i == n - 1) {
            if (nums[i] != nums[i - 1])
                return nums[i];
        }
        else {
            if (nums[i] != nums[i - 1] && nums[i] != nums[i + 1])
                return nums[i];
        }
        }
        return -1;
    }
};

