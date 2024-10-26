/*
You are given the root of a binary tree with n nodes. Each node is assigned a unique value from 1 to n. You are also given an array queries of size m.

You have to perform m independent queries on the tree where in the ith query you do the following:

Remove the subtree rooted at the node with the value queries[i] from the tree. It is guaranteed that queries[i] will not be equal to the value of the root.
Return an array answer of size m where answer[i] is the height of the tree after performing the ith query.

Note:

The queries are independent, so the tree returns to its initial state after each query.
The height of a tree is the number of edges in the longest simple path from the root to some node in the tree.
 

Example 1:


Input: root = [1,3,4,2,null,6,5,null,null,null,null,null,7], queries = [4]
Output: [2]
Explanation: The diagram above shows the tree after removing the subtree rooted at node with value 4.
The height of the tree is 2 (The path 1 -> 3 -> 2).
Example 2:


Input: root = [5,8,9,2,1,3,7,4,6], queries = [3,2,4,8]
Output: [3,2,3,2]
Explanation: We have the following queries:
- Removing the subtree rooted at node with value 3. The height of the tree becomes 3 (The path 5 -> 8 -> 2 -> 4).
- Removing the subtree rooted at node with value 2. The height of the tree becomes 2 (The path 5 -> 8 -> 1).
- Removing the subtree rooted at node with value 4. The height of the tree becomes 3 (The path 5 -> 8 -> 2 -> 6).
- Removing the subtree rooted at node with value 8. The height of the tree becomes 2 (The path 5 -> 9 -> 3).

*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    int traverse(TreeNode* root, unordered_map<int,int>&height,int lv, unordered_map<int,int>&level){

        if(root==nullptr) return 0;

        if(root->left!=nullptr){
            level[root->left->val] = lv;
        }

         if(root->right!=nullptr){
            level[root->right->val] = lv;
        }

        int l = traverse(root->left,height,lv+1,level);
        int r = traverse(root->right,height,lv+1,level);

        int h = max(l,r) +1;
        height[root->val] = h;
        return h;

    }

    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {

        unordered_map<int,int> height;
        unordered_map<int,int> level;

        int h = traverse(root,height,1,level);

        //group nodes at the same level

        unordered_map<int,vector<int>> m;

        for(auto i:level){
            m[i.second].push_back(i.first);
        }

        

        unordered_map<int,int> del;

        for(int i=1;i<h;i++){
            //level i
            int max = 0;
            int secmax = 0;

            int maxint = -1;

            if(m[i].size()==1){
                del[m[i][0]] = level[m[i][0]]-1;
                continue;
            }

            for(int k=0;k<m[i].size();k++){
                if(height[m[i][k]]>max) {
                    secmax = max;
                    max = height[m[i][k]];
                    maxint = m[i][k];
                }
                else if(height[m[i][k]]>secmax) secmax = height[m[i][k]];
            }

            for(int k=0;k<m[i].size();k++){
                if(m[i][k]==maxint) {
                    del[m[i][k]] = secmax + level[m[i][k]] -1;
                }
                else del[m[i][k]] = max + level[m[i][k]] -1;
            }
        }

        vector<int> ans;

        for(int i=0;i<queries.size();i++){
            
             ans.push_back(del[queries[i]]);

        }

        return ans;
        
    }
};
