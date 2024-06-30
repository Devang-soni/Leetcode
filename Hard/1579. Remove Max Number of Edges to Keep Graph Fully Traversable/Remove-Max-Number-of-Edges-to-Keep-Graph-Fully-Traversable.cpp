/*
Alice and Bob have an undirected graph of n nodes and three types of edges:

Type 1: Can be traversed by Alice only.
Type 2: Can be traversed by Bob only.
Type 3: Can be traversed by both Alice and Bob.
Given an array edges where edges[i] = [typei, ui, vi] represents a bidirectional edge of type typei between nodes ui and vi, find the maximum number of edges you can remove so that after removing the edges, the graph can still be fully traversed by both Alice and Bob. The graph is fully traversed by Alice and Bob if starting from any node, they can reach all other nodes.
Return the maximum number of edges you can remove, or return -1 if Alice and Bob cannot fully traverse the graph.

Example 1:

Input: n = 4, edges = [[3,1,2],[3,2,3],[1,1,3],[1,2,4],[1,1,2],[2,3,4]]
Output: 2
Explanation: If we remove the 2 edges [1,1,2] and [1,1,3]. The graph will still be fully traversable by Alice and Bob. Removing any additional edge will not make it so. So the maximum number of edges we can remove is 2.
Example 2:

Input: n = 4, edges = [[3,1,2],[3,2,3],[1,1,4],[2,1,4]]
Output: 0
Explanation: Notice that removing any edge will not make the graph fully traversable by Alice and Bob.
Example 3:

Input: n = 4, edges = [[3,2,3],[1,1,2],[2,3,4]]
Output: -1
Explanation: In the current graph, Alice cannot reach node 4 from the other nodes. Likewise, Bob cannot reach 1. Therefore it's impossible to make the graph fully traversable.
 
*/

class DisjointSet {
    vector<int> rank, parent;
public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};

class Solution {
public:


    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DisjointSet Alice(n);
        DisjointSet Bob(n);
        int ans = 0;
        for(int i=0;i<edges.size();i++){
            if(edges[i][0] == 3){
                bool a = Alice.findUPar(edges[i][1]) == Alice.findUPar(edges[i][2]);
                bool b = Bob.findUPar(edges[i][1]) == Bob.findUPar(edges[i][2]);
                if(a && b)
                    ans++;
                else if(!a && b)
                    Alice.unionByRank(edges[i][1],edges[i][2]);
                else if(a && !b)
                    Bob.unionByRank(edges[i][1],edges[i][2]);
                else if(!a && !b){
                    Alice.unionByRank(edges[i][1],edges[i][2]);
                    Bob.unionByRank(edges[i][1],edges[i][2]);
                }
            }
        }

        for(int i=0;i<edges.size();i++){
            if(edges[i][0] == 1){
                bool a = Alice.findUPar(edges[i][1]) == Alice.findUPar(edges[i][2]);
                if(a)
                    ans++;
                else
                    Alice.unionByRank(edges[i][1],edges[i][2]);
            }
            else if(edges[i][0] == 2){
                bool b = Bob.findUPar(edges[i][1]) == Bob.findUPar(edges[i][2]);
                if(b)
                    ans++;
                else
                    Bob.unionByRank(edges[i][1],edges[i][2]);
            }
        }
        int al = Alice.findUPar(1);
        int bo = Bob.findUPar(1);
        for(int i=1;i<=n;i++){
            if(al != Alice.findUPar(i))
                return -1;
            if(bo != Bob.findUPar(i))
                return -1;
        }
        return ans;
    }
};
