/*  
You are given m arrays, where each array is sorted in ascending order.

You can pick up two integers from two different arrays (each array picks one) and calculate the distance. We define the distance between two integers a and b to be their absolute difference |a - b|.

Return the maximum distance.

 

Example 1:

Input: arrays = [[1,2,3],[4,5],[1,2,3]]
Output: 4
Explanation: One way to reach the maximum distance 4 is to pick 1 in the first or third array and pick 5 in the second array.
Example 2:

Input: arrays = [[1],[1]]
Output: 0
 
*/

class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int mini = INT_MAX;
        int maxi = INT_MIN;

        int ans = INT_MIN;
        for(auto it: arrays){
            int n = it.size();
            if(maxi != INT_MIN && mini != INT_MAX){
                int d1 = abs(it[0]-maxi);
                int d2 = abs(it[n-1]-mini);
                ans = max({ans,d1,d2});
            }
            maxi = max(maxi, it[n-1]);
            mini = min(mini, it[0]);
        }
        return ans;
    }
};
