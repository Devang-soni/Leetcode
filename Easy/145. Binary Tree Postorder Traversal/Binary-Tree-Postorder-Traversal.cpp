/*
Given the root of a binary tree, return the postorder traversal of its nodes' values.

 

Example 1:


Input: root = [1,null,2,3]
Output: [3,2,1]
Example 2:

Input: root = []
Output: []
Example 3:

Input: root = [1]
Output: [1]

*/

class Solution {
public:
   vector<int>ans;
   void postorder(TreeNode*root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
         ans.push_back(root->val);
    }
   }
    vector<int> postorderTraversal(TreeNode* root) {
        postorder(root);
        return ans;
    }
};
