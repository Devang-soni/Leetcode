/*
You are given an undirected weighted graph of n nodes (0-indexed), represented by an edge list where edges[i] = [a, b] is an undirected edge connecting the nodes a and b with a probability of success of traversing that edge succProb[i].

Given two nodes start and end, find the path with the maximum probability of success to go from start to end and return its success probability.

If there is no path from start to end, return 0. Your answer will be accepted if it differs from the correct answer by at most 1e-5.

 

Example 1:



Input: n = 3, edges = [[0,1],[1,2],[0,2]], succProb = [0.5,0.5,0.2], start = 0, end = 2
Output: 0.25000
Explanation: There are two paths from start to end, one having a probability of success = 0.2 and the other has 0.5 * 0.5 = 0.25.
Example 2:



Input: n = 3, edges = [[0,1],[1,2],[0,2]], succProb = [0.5,0.5,0.3], start = 0, end = 2
Output: 0.30000
Example 3:



Input: n = 3, edges = [[0,1]], succProb = [0.5], start = 0, end = 2
Output: 0.00000
Explanation: There is no path between 0 and 2.
*/


class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {

        // Priority queue to store {probability, node} with max heap
        priority_queue<pair<double, int>> pq;

        // Adjacency list to store graph
        vector<vector<pair<int, double>>> adj(n);

        // Probability vector initialized to 0.0
        vector<double> probability(n, 0.0);

        // Building adjacency list
        for (int i = 0; i < edges.size(); ++i) {
            adj[edges[i][0]].push_back({edges[i][1], succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }

        // Start with the starting node, probability 1.0 (100%)
        pq.push({1.0, start_node});
        probability[start_node] = 1.0;

        while (!pq.empty()) {
            double current_prob = pq.top().first;
            int source = pq.top().second;
            pq.pop();

            // If we reached the end node, return the probability
            if (source == end_node) return current_prob;

            for (auto& edg : adj[source]) {
                int next_vertex = edg.first;
                double edge_prob = edg.second;

                // If we found a path with a higher probability, update it
                if (current_prob * edge_prob > probability[next_vertex]) {
                    probability[next_vertex] = current_prob * edge_prob;
                    pq.push({probability[next_vertex], next_vertex});
                }
            }
        }

        // If we couldn't reach the end node, return 0.0
        return 0.0;
    }
};
