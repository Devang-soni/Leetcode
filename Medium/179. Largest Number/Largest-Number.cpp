/*
Given a list of non-negative integers nums, arrange them such that they form the largest number and return it.

Since the result may be very large, so you need to return a string instead of an integer.

 

Example 1:

Input: nums = [10,2]
Output: "210"
Example 2:

Input: nums = [3,30,34,5,9]
Output: "9534330"
 
*/

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end(),[&](int a,int b){
            string order1 = to_string(a)+to_string(b);
            string order2 = to_string(b)+to_string(a);
            return order1>order2;
        });
        
        string ans = "";
        for(int i = 0;i<nums.size();i++){
            if(nums[0]==0) return "0";
            ans += to_string(nums[i]);
        }
        return ans;
    }
};
