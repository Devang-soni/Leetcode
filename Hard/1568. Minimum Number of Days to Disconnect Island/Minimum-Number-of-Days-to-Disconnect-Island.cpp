/*
You are given an m x n binary grid grid where 1 represents land and 0 represents water. An island is a maximal 4-directionally (horizontal or vertical) connected group of 1's.

The grid is said to be connected if we have exactly one island, otherwise is said disconnected.

In one day, we are allowed to change any single land cell (1) into a water cell (0).

Return the minimum number of days to disconnect the grid.

 

Example 1:


Input: grid = [[0,1,1,0],[0,1,1,0],[0,0,0,0]]

Output: 2
Explanation: We need at least 2 days to get a disconnected grid.
Change land grid[1][1] and grid[0][2] to water and get 2 disconnected island.
Example 2:


Input: grid = [[1,1]]
Output: 2
Explanation: Grid of full water is also disconnected ([[1,1]] -> [[0,0]]), 0 islands.
*/

class Solution {
public:
    int dirs[5] = { 0, 1, 0, -1, 0 };
    int n, m;
    int visitedCount = 0;
    bool dfs(int i, int j, int pi, int pj, int time, 
        vector<vector<bool>>& visited,
        vector<vector<int>>& tin,
        vector<vector<int>>& low,
        vector<vector<int>>& grid
        )
    {
        visited[i][j] = true;
        visitedCount++;
        low[i][j] = tin[i][j] = time++;
        int children = 0;
        int ans = false;
        for (int di = 0; di < 4; di++) {
            int ii = i + dirs[di];
            int jj = j + dirs[di+1];
            if (ii < 0 || ii == n || jj < 0 || jj == m) continue;
            if (grid[ii][jj] == 0) continue;
            if (ii == pi && jj == pj) continue;
            if (visited[ii][jj]) {
                low[i][j] = min(low[i][j], tin[ii][jj]);
            } else {
                if (dfs(ii, jj, i, j, time, visited, tin, low, grid)) {
                    ans = true;
                }
                low[i][j] = min(low[i][j], low[ii][jj]);
                if (low[ii][jj] >= tin[i][j] && pi != -1 && pj != -1) {
                    ans = true;
                }
                children++;
            }
        }
        if (pi == -1 && pj == -1 && children > 1) {
            ans = true;
        }
        return ans;
    }
    int minDays(vector<vector<int>>& grid) {
        n = grid.size(); m = grid[0].size();
        vector<vector<int>> tin(n, vector<int>(m));
        vector<vector<int>> low(n, vector<int>(m));
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int found = 0;
        int ones = 0;
        int ii, jj;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j]) {
                    ones++;
                    ii = i;
                    jj = j;
                }
            }
        }

        if (ones == 1) return 1; // edge case
        if (ones == 0) return 0; // edge case
        bool hasArticulationPoint = dfs(ii, jj, -1, -1, 0, visited, tin, low, grid);
        if (ones != visitedCount) {
            return 0;
        }

        return hasArticulationPoint ? 1 : 2;
    }
};

