/*
Given a 0-indexed integer array nums of size n and two integers lower and upper, return the number of fair pairs.

A pair (i, j) is fair if:

0 <= i < j < n, and
lower <= nums[i] + nums[j] <= upper
 

Example 1:

Input: nums = [0,1,7,4,4,5], lower = 3, upper = 6
Output: 6
Explanation: There are 6 fair pairs: (0,3), (0,4), (0,5), (1,3), (1,4), and (1,5).
Example 2:

Input: nums = [1,7,9,2,5], lower = 11, upper = 11
Output: 1
Explanation: There is a single fair pair: (2,3).
*/

class Solution {
public:
    long long countFairPairs(vector<int>& arr, int lower, int upper) 
    {
        int n = arr.size();
        
        sort(arr.begin(), arr.end());
        
        long long ans = 0;
        
        for(int i=0; i<n; i++)
        {
            int val = upper - arr[i];
            int cal = lower - arr[i];
            
            auto ind = upper_bound(arr.begin(), arr.end(), val);
            auto ind1 = lower_bound(arr.begin(), arr.end(), cal);
            
            int index = ind-arr.begin()-1;
            int index1 = ind1-arr.begin();
            
         
            if(index1 < 0 || index < 0) continue;
            
            if(index >= i) 
            {
                if(index1 > i) ans += index-index1+1;
                else ans += index-max(index1, i);
            }
        }
        
        return ans;
     }
};
