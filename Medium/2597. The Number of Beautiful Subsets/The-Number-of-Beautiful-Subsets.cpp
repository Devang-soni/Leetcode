/*
You are given an array nums of positive integers and a positive integer k.

A subset of nums is beautiful if it does not contain two integers with an absolute difference equal to k.

Return the number of non-empty beautiful subsets of the array nums.

A subset of nums is an array that can be obtained by deleting some (possibly none) elements from nums. Two subsets are different if and only if the chosen indices to delete are different.
*/

class Solution {
public:
    int dfs(vector<int>& nums, int k,int i,unordered_map<int,int>& p){
        if(i == nums.size()){
            return 1;
        }
        int t = 0;
        if(!p[nums[i]-k] && !p[nums[i]+k]){
            p[nums[i]]++;
            t=dfs(nums,k,i+1,p);
            p[nums[i]]--;
        }
        int nt = dfs(nums,k,i+1,p);
        return t+nt;
    }
    int beautifulSubsets(vector<int>& nums, int k) {
       unordered_map<int,int>p;
       int ans = dfs(nums,k,0,p);
       return ans-1;

    }
};
