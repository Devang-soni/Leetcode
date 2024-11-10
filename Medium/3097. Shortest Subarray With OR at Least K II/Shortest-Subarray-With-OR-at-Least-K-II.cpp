/*
You are given an array nums of non-negative integers and an integer k.

An array is called special if the bitwise OR of all of its elements is at least k.

Return the length of the shortest special non-empty 
subarray
 of nums, or return -1 if no special subarray exists.

 

Example 1:

Input: nums = [1,2,3], k = 2

Output: 1

Explanation:

The subarray [3] has OR value of 3. Hence, we return 1.

Example 2:

Input: nums = [2,1,8], k = 10

Output: 3

Explanation:

The subarray [2,1,8] has OR value of 11. Hence, we return 3.

Example 3:

Input: nums = [1,2], k = 0

Output: 1

Explanation:

The subarray [1] has OR value of 1. Hence, we return 1.

 
*/

class Solution {
    void addContribution(int val,vector<int>& bitArray,bool flag){
        int i = 0;
        while(val > 0){
            bitArray[i] += (flag ? 1 : -1) * (val % 2);
            val /= 2;
            i++;
        }
    }

    bool isValid(vector<int>& bitArray,int k){
        int val = 0;
        for(int i = 0; i < 32; i++){
            val = val + (bitArray[i] ? 1 : 0) * (pow(2,i));
        }
        return val >= k;
    }
    
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0;
        int ans = 1e9;
        vector<int> bitArray(32,0);
        for(int right = 0; right < n; right++){
            addContribution(nums[right],bitArray,true);
            while(left <= right && isValid(bitArray,k)){
                ans = min(ans,right-left+1);
                addContribution(nums[left],bitArray,false);
                left++;
            }
        }
        return ans == 1e9 ? -1 : ans;
        
    }
};
