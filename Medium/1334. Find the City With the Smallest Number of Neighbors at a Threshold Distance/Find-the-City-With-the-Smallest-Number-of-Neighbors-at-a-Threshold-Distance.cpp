/*
There are n cities numbered from 0 to n-1. Given the array edges where edges[i] = [fromi, toi, weighti] represents a bidirectional and weighted edge between cities fromi and toi, and given the integer distanceThreshold.

Return the city with the smallest number of cities that are reachable through some path and whose distance is at most distanceThreshold, If there are multiple such cities, return the city with the greatest number.

Notice that the distance of a path connecting cities i and j is equal to the sum of the edges' weights along that path.

 

Example 1:


Input: n = 4, edges = [[0,1,3],[1,2,1],[1,3,4],[2,3,1]], distanceThreshold = 4
Output: 3
Explanation: The figure above describes the graph. 
The neighboring cities at a distanceThreshold = 4 for each city are:
City 0 -> [City 1, City 2] 
City 1 -> [City 0, City 2, City 3] 
City 2 -> [City 0, City 1, City 3] 
City 3 -> [City 1, City 2] 
Cities 0 and 3 have 2 neighboring cities at a distanceThreshold = 4, but we have to return city 3 since it has the greatest number.
Example 2:


Input: n = 5, edges = [[0,1,2],[0,4,8],[1,2,3],[1,4,2],[2,3,1],[3,4,1]], distanceThreshold = 2
Output: 0
Explanation: The figure above describes the graph. 
The neighboring cities at a distanceThreshold = 2 for each city are:
City 0 -> [City 1] 
City 1 -> [City 0, City 4] 
City 2 -> [City 3, City 4] 
City 3 -> [City 2, City 4]
City 4 -> [City 1, City 2, City 3] 
The city 0 has 1 neighboring city at a distanceThreshold = 2.
*/

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>adj(n,vector<int>(n,1e9));
// FOR THIS QUESTION WE NEED TO IMPLEMENT FLOYD WARSHALL TO GET THE MINIMUM DISTANCE FROM ALL THE SOURCES SO WE 
// CREATE AN ADJACENCY MATRIX AND SINCE IT IS AN UNDIRECTED GRAPH WE ADD WEIGHTS ON BOTH THE NODES  
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]][edges[i][1]]=edges[i][2];
            adj[edges[i][1]][edges[i][0]]=edges[i][2];
        }
// ONCE ADJANCENCY MATRIX IS MADE WE IMPLEMENT THE FLOYD WARSHALL FOR ALL NODES  
// AND TAKE THE MINIMUM AS PER THE FORMULA adj[i][j]=min(adj[i][j],adj[i][k]+adj[k][j])
// AND SINCE THE NODES HAVE 0 DISTANCE FOR THEMSELVES SO WHEN AT I=J WE MAKE 0
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(i!=j){
                        adj[i][j]=min(adj[i][j],adj[i][k]+adj[k][j]);
                    }
                    else if(i==j)adj[i][j]=0;
                }
            }
        }
// ONCE THE ADJACENCY MATRIX IS MADE WE CHECK FOR THOSE DISTANCES WHICH ARE LESS THAN THRESHOLD
// AND CREATE A 2D VECTOR CITY TO STORE SUCH DISTANCES FOR ALL THE RESPECTIVE NODES
// WE ALSO CHECK WHICH IS MINIMUM NUMBER OF SUCH DISTANCES FOR ANY NODE
        int minsize=INT_MAX;
        vector<vector<int>>city(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j){
                    if(adj[i][j]<=distanceThreshold){
                        city[i].push_back(adj[i][j]);
                    }
                }
            }
            if(city[i].size()<minsize){
                minsize=city[i].size();
            }
        }
// FINALLY WE KNOW THAT MINIMUM DISTANCES IS minsize  
// NOW WE CAN JUST CHECK WHICH IS THE LAST NODE TO HAVE HAD THAT MIN SIZE AND RETURN THAT NODE , 
// BECAUSE IN QUESTION IT IS ASKED TO RETURN GREATER IF MORE THAN ONE EXIST
// THIS COULD ASLO BE CHECKED IN THE UPPER PART WHERE WE ARE FINDING THE minsize 
        int ansnode;
        for(int i=0;i<city.size();i++){
            if(city[i].size()==minsize){
                ansnode=i;
            }
        }
        return ansnode;
    }
};
