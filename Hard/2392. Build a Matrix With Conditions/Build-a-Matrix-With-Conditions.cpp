/*
You are given a positive integer k. You are also given:

a 2D integer array rowConditions of size n where rowConditions[i] = [abovei, belowi], and
a 2D integer array colConditions of size m where colConditions[i] = [lefti, righti].
The two arrays contain integers from 1 to k.

You have to build a k x k matrix that contains each of the numbers from 1 to k exactly once. The remaining cells should have the value 0.

The matrix should also satisfy the following conditions:

The number abovei should appear in a row that is strictly above the row at which the number belowi appears for all i from 0 to n - 1.
The number lefti should appear in a column that is strictly left of the column at which the number righti appears for all i from 0 to m - 1.
Return any matrix that satisfies the conditions. If no answer exists, return an empty matrix.

 

Example 1:


Input: k = 3, rowConditions = [[1,2],[3,2]], colConditions = [[2,1],[3,2]]
Output: [[3,0,0],[0,0,1],[0,2,0]]
Explanation: The diagram above shows a valid example of a matrix that satisfies all the conditions.
The row conditions are the following:
- Number 1 is in row 1, and number 2 is in row 2, so 1 is above 2 in the matrix.
- Number 3 is in row 0, and number 2 is in row 2, so 3 is above 2 in the matrix.
The column conditions are the following:
- Number 2 is in column 1, and number 1 is in column 2, so 2 is left of 1 in the matrix.
- Number 3 is in column 0, and number 2 is in column 1, so 3 is left of 2 in the matrix.
Note that there may be multiple correct answers.
Example 2:

Input: k = 3, rowConditions = [[1,2],[2,3],[3,1],[2,3]], colConditions = [[2,1]]
Output: []
Explanation: From the first two conditions, 3 has to be below 1 but the third conditions needs 3 to be above 1 to be satisfied.
No matrix can satisfy all the conditions, so we return the empty matrix.
*/

class Solution {
public:
    vector<vector<int>> buildGraph(int k, vector<vector<int>>&graph)
    {
        vector<vector<int>>adj(k+1);
        for(auto it: graph)
        {
            adj[it[0]].push_back(it[1]);
        }
        return adj;
    }

    vector<int> toposort(int k, vector<vector<int>>&adj)
    {
        vector<int>topo;
        vector<int>indegree(k+1,0);

        for(int u=1;u<=k;u++)
        {
            for(int v: adj[u])
            {
                indegree[v]++;
            }
        }

        queue<int>q;
        vector<bool>vis(k+1,false);

        for(int u=1;u<=k;u++)
        {
            if(indegree[u] == 0)
                q.push(u);
        }

        while(!q.empty())
        {
            int u = q.front();
            q.pop();

            topo.push_back(u);

            for(int v: adj[u])
            {
                indegree[v]--;

                if(indegree[v] == 0)
                {
                    q.push(v);
                }
            }
        }

        for(int u=1;u<=k;u++)
        {
            if(indegree[u] != 0)
            {
                return {};
            }
        }

        return topo;
    }

    void fillTopo(int k, vector<int>&topo)
    {
        unordered_map<int,bool>vis;

        for(int u: topo)
            vis[u] = true;

        for(int u=1;u<=k;u++)
        {
            if(!vis[u])
            {
                topo.push_back(u);
            }
        }
    }

    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) 
    {
        vector<vector<int>>row = buildGraph(k,rowConditions);
        vector<vector<int>>col = buildGraph(k,colConditions); 

        vector<int>rowTopo = toposort(k, row);
        vector<int>colTopo = toposort(k, col); 

        if(rowTopo.empty() || colTopo.empty())
            return {};

        vector<vector<int>>mat(k,vector<int>(k,0));

        fillTopo(k,rowTopo);
        fillTopo(k,colTopo);

        unordered_map<int,int>colInd;
        for(int j=0;j<k;j++)
        {
            colInd[colTopo[j]] = j;
        }  

        for(int i=0;i<k;i++)
        {
            mat[i][colInd[rowTopo[i]]] = rowTopo[i];
        }

        return mat;
    }
};

