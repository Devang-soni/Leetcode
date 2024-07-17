/*
Given the root of a binary tree, each node in the tree has a distinct value.

After deleting all nodes with a value in to_delete, we are left with a forest (a disjoint union of trees).

Return the roots of the trees in the remaining forest. You may return the result in any order.

 

Example 1:


Input: root = [1,2,3,4,5,6,7], to_delete = [3,5]
Output: [[1,2,null,4],[6],[7]]
Example 2:

Input: root = [1,2,4,null,3], to_delete = [3]
Output: [[1,2,4]]
*/

class Solution {
public:
    TreeNode* getForest(TreeNode* root, set<int>& st, vector<TreeNode*>& result) {
        if(!root)
            return NULL;
        
        root->left  = getForest(root->left, st, result);
        root->right = getForest(root->right, st, result);
        
        if(st.count(root->val)) {
            if(root->left)
                result.push_back(root->left);
            if(root->right)
                result.push_back(root->right);
            return NULL;
        }
        
        return root;
    }
    
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        if(!root)
            return {};
        
        vector<TreeNode*> result;
        set<int> st;
        for(int node:to_delete)
            st.insert(node);
        
        getForest(root, st, result);
        if(!st.count(root->val)) {
            result.push_back(root);
        }
        return result;
    }
};
