/*
You are given an undirected weighted connected graph containing n nodes labeled from 0 to n - 1, and an integer array edges where edges[i] = [ai, bi, wi] indicates that there is an edge between nodes ai and bi with weight wi.

Some edges have a weight of -1 (wi = -1), while others have a positive weight (wi > 0).

Your task is to modify all edges with a weight of -1 by assigning them positive integer values in the range [1, 2 * 109] so that the shortest distance between the nodes source and destination becomes equal to an integer target. If there are multiple modifications that make the shortest distance between source and destination equal to target, any of them will be considered correct.

Return an array containing all edges (even unmodified ones) in any order if it is possible to make the shortest distance from source to destination equal to target, or an empty array if it's impossible.

Note: You are not allowed to modify the weights of edges with initial positive weights.

 

Example 1:



Input: n = 5, edges = [[4,1,-1],[2,0,-1],[0,3,-1],[4,3,-1]], source = 0, destination = 1, target = 5
Output: [[4,1,1],[2,0,1],[0,3,3],[4,3,1]]
Explanation: The graph above shows a possible modification to the edges, making the distance from 0 to 1 equal to 5.
Example 2:



Input: n = 3, edges = [[0,1,-1],[0,2,5]], source = 0, destination = 2, target = 6
Output: []
Explanation: The graph above contains the initial edges. It is not possible to make the distance from 0 to 2 equal to 6 by modifying the edge with weight -1. So, an empty array is returned.
Example 3:



Input: n = 4, edges = [[1,0,4],[1,2,3],[2,3,5],[0,3,-1]], source = 0, destination = 2, target = 6
Output: [[1,0,4],[1,2,3],[2,3,5],[0,3,1]]
Explanation: The graph above shows a modified graph having the shortest distance from 0 to 2 as 6.
*/

class Solution {
public:
    int dijkstra(int source, int destination, vector<vector<pair<int, int>>> &adj){
        vector<int> dist(adj.size(), INT_MAX);
        dist[source] = 0; 
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // {dist, node}
        pq.push({0, source});
        while (!pq.empty()){
            auto front = pq.top(); 
            pq.pop(); 
            int node = front.second;
            // int currdist = front.first; 
            for (auto it: adj[node]){
                int neigh = it.first; 
                int nwt = it.second; 
                if (dist[node] + nwt < dist[neigh]){
                    dist[neigh] = dist[node] + nwt; 
                    pq.push({dist[neigh], neigh});
                }
            }
        }
        return dist[destination];
    }

    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
        // first we will find the distance b/w source and destination without considering the negative edges
        // if the distance comes out to be less than target then return empty list
        // else now we will pick negative edges 1 by one and add it to the graph and apply shortest distance algo (dijkstra) and find the shortest distance if it comes out to be less than target than just update the value of the edge picked and do it for all the edges 
        // agar abhi tak nhi mila toh return empty list 

        // main intuition or though process was that: we should first not consider the negative edges and add them one by one

        vector<vector<pair<int, int>>> adj(n); 
        for (auto it: edges){
            int wt = it[2]; 
            if (wt == -1) continue; 
            int u = it[0];
            int v = it[1];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        // now apply dijkstra
        int shortestPath = dijkstra(source, destination, adj);
        if (shortestPath < target){
            return {};
        }
        if (shortestPath == target){
            for (int i = 0; i<edges.size(); i++){
                int wt = edges[i][2];
                if (wt == -1){
                    edges[i][2] = 1e9; 
                }
            }
            return edges; 
        }

        for (int i = 0; i<edges.size(); i++){
            int wt = edges[i][2];
            if (wt == -1){
                edges[i][2] = 1;
                int u = edges[i][0];
                int v = edges[i][1];
                adj[u].push_back({v, 1});
                adj[v].push_back({u, 1}); 
                int shortestPath = dijkstra(source, destination, adj);
                if (shortestPath <= target){
                    edges[i][2] += (target - shortestPath);
                    for (int j = 0; j<edges.size(); j++){
                        int wt = edges[j][2];
                        if (wt == -1){
                            edges[j][2] = 1e9; 
                        }
                    }
                    return edges;
                }
            }
        }

        return {};

    }
};
