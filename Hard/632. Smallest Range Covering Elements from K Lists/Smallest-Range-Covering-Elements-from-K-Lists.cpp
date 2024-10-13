/*
You have k lists of sorted integers in non-decreasing order. Find the smallest range that includes at least one number from each of the k lists.

We define the range [a, b] is smaller than range [c, d] if b - a < d - c or a < c if b - a == d - c.

 

Example 1:

Input: nums = [[4,10,15,24,26],[0,9,12,20],[5,18,22,30]]
Output: [20,24]
Explanation: 
List 1: [4, 10, 15, 24,26], 24 is in range [20,24].
List 2: [0, 9, 12, 20], 20 is in range [20,24].
List 3: [5, 18, 22, 30], 22 is in range [20,24].
Example 2:

Input: nums = [[1,2,3],[1,2,3],[1,2,3]]
Output: [1,1]

*/
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        // {value,{rowIndex, colIndex}}
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<>> pq;

        int s=0, e=INT_MAX, maxi=INT_MIN, k=nums.size();

        for(int i=0; i<k; i++){
            pq.push({nums[i][0], {i,0}});
            maxi=max(maxi,nums[i][0]);
        }

        while(1){
            auto it=pq.top();
            pq.pop();
            int mini=it.first;
            int r=it.second.first;
            int c=it.second.second;

            if(maxi-mini < e-s){
                e=maxi;
                s=mini;
            }

            if(c+1==nums[r].size()) break;

            int next=nums[r][c+1];
            pq.push({next,{r,c+1}});
            maxi=max(maxi,next);
        }

        return {s,e};
    }
};
