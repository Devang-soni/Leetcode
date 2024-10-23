/*
Given the root of a binary tree, replace the value of each node in the tree with the sum of all its cousins' values.

Two nodes of a binary tree are cousins if they have the same depth with different parents.

Return the root of the modified tree.

Note that the depth of a node is the number of edges in the path from the root node to it.

 

Example 1:


Input: root = [5,4,9,1,10,null,7]
Output: [0,0,0,7,7,null,11]
Explanation: The diagram above shows the initial binary tree and the binary tree after changing the value of each node.
- Node with value 5 does not have any cousins so its sum is 0.
- Node with value 4 does not have any cousins so its sum is 0.
- Node with value 9 does not have any cousins so its sum is 0.
- Node with value 1 has a cousin with value 7 so its sum is 7.
- Node with value 10 has a cousin with value 7 so its sum is 7.
- Node with value 7 has cousins with values 1 and 10 so its sum is 11.
Example 2:


Input: root = [3,1,2]
Output: [0,0,0]
Explanation: The diagram above shows the initial binary tree and the binary tree after changing the value of each node.
- Node with value 3 does not have any cousins so its sum is 0.
- Node with value 1 does not have any cousins so its sum is 0.
- Node with value 2 does not have any cousins so its sum is 0.

*/

class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) 
    {
        queue<TreeNode*>q;
        q.push(root);

        vector<int>store;
        int depth = 0, size, sum;
        while(!q.empty())
        {
            sum = 0, size = q.size();
            while(size--)
            {
                auto node = q.front(); q.pop();
                sum += node->val;

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            store.push_back(sum);
        }
        store.push_back(store.back());
        
        q.push(root);
        root->val = 0;
        while(!q.empty())
        {
            depth += 1;
            size = q.size();
            while(size--)
            {
                sum = store[depth];
                auto node = q.front(); q.pop();
                
                if(node->left)
                {
                    q.push(node->left);
                    sum -= node->left->val;
                }
                if(node->right)
                {
                    q.push(node->right);
                    sum -= node->right->val;
                }

                if(node->left) node->left->val = sum;
                if(node->right) node->right->val = sum;
            }
        }
        return root;
    }
};
