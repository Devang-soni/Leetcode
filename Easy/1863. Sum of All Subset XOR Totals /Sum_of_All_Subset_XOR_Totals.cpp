/*
    The XOR total of an array is defined as the bitwise XOR of all its elements, or 0 if the array is empty.

For example, the XOR total of the array [2,5,6] is 2 XOR 5 XOR 6 = 1.
Given an array nums, return the sum of all XOR totals for every subset of nums. 

Note: Subsets with the same elements should be counted multiple times.

An array a is a subset of an array b if a can be obtained from b by deleting some (possibly zero) elements of b.
*/

class Solution {
    int result;
    void helper(vector<int>& nums,int sum,int i)
    {
        if(i==nums.size()-1) {
            result+= sum + (sum^nums[i]);
            return;
        }
        helper(nums,sum,i+1);
        helper(nums,sum^nums[i],i+1);
    }
public:
    int subsetXORSum(vector<int>& nums) {
        result=0;
        helper(nums,0,0);
        return result;
    }
};
