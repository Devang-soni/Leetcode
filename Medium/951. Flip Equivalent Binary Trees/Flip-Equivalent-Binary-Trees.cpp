/*
For a binary tree T, we can define a flip operation as follows: choose any node, and swap the left and right child subtrees.

A binary tree X is flip equivalent to a binary tree Y if and only if we can make X equal to Y after some number of flip operations.

Given the roots of two binary trees root1 and root2, return true if the two trees are flip equivalent or false otherwise.

 

Example 1:

Flipped Trees Diagram
Input: root1 = [1,2,3,4,5,6,null,null,null,7,8], root2 = [1,3,2,null,6,4,5,null,null,null,null,8,7]
Output: true
Explanation: We flipped at nodes with values 1, 3, and 5.
Example 2:

Input: root1 = [], root2 = []
Output: true
Example 3:

Input: root1 = [], root2 = [1]
Output: false

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
/*DFS traversal to record the child nodes of each parent node into
 the vtr array*/
    void dfs(TreeNode* r,vector<vector<int>>&vtr,int fa)
    {
        if(r==nullptr)
        return ;
        vtr[fa].push_back(r->val);
        dfs(r->left,vtr,r->val);
        dfs(r->right,vtr,r->val);
    }
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
     /*Looking at the data range, it is recommended to use an x-y 
coordinate system to correspond to the parent-child relationship of
 the nodes.*/
        vector<vector<int>>vtr1(101),vtr2(101);
//The 'parent node' of the root node is 100
        dfs(root1,vtr1,100);
        dfs(root2,vtr2,100);
//Compare to see if they are equal
        for(int i=0;i<101;i++)
        {
            sort(vtr1[i].begin(),vtr1[i].end());
            sort(vtr2[i].begin(),vtr2[i].end());
            if(vtr1[i]!=vtr2[i])
            return false;
        }
       return true;
        
    }
};
