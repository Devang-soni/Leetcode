/*
Given the root of a binary search tree, return a balanced binary search tree with the same node values. If there is more than one answer, return any of them.

A binary search tree is balanced if the depth of the two subtrees of every node never differs by more than 1.

Example 1:

Input: root = [1,null,2,null,3,null,4,null,null]
Output: [2,1,3,null,null,null,4]
Explanation: This is not the only correct answer, [3,1,4,null,2] is also correct.
Example 2:


Input: root = [2,1,3]
Output: [2,1,3]
*/

{
public:
    vector<TreeNode*> currentNodes;

    TreeNode* balanceBST(TreeNode* root) {
        preOrder(root);
        return balance(0, currentNodes.size() - 1);
    }

private:
    TreeNode* balance(int i, int j) {
        if (i > j)
            return nullptr;

        int mid = i + (j - i) / 2;
        TreeNode* res = currentNodes[mid];
        res->left = balance(i, mid - 1);
        res->right = balance(mid + 1, j);
        return res;
    }

    void preOrder(TreeNode* root) {
        if (root == nullptr)
            return;

        preOrder(root->left);
        currentNodes.push_back(root);
        preOrder(root->right);
    }
};

