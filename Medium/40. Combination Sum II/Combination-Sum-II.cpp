/*
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.

 

Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]
Example 2:

Input: candidates = [2,5,2,1,2], target = 5
Output: 
[
[1,2,2],
[5]
]
 
*/

class Solution {
public:
    void findCombi(int idx,vector<int>& candidates,vector<vector<int>>& ans,int target,vector<int>& currCombi){
        if(target==0){
            ans.push_back(currCombi);
        }
        for(int i = idx;i<candidates.size();i++){
            if(i>idx && candidates[i]==candidates[i-1]){
                continue;
            }
            if(candidates[i]>target){
                break; //since candidates is sorted , so forward ele will be > also.
            }
            currCombi.push_back(candidates[i]);
            findCombi(i+1,candidates,ans,target-candidates[i],currCombi);
            currCombi.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> currCombi;
        findCombi(0,candidates,ans,target,currCombi);
        return ans;
    }
};
