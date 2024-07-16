/*
You are given the root of a binary tree with n nodes. Each node is uniquely assigned a value from 1 to n. You are also given an integer startValue representing the value of the start node s, and a different integer destValue representing the value of the destination node t.

Find the shortest path starting from node s and ending at node t. Generate step-by-step directions of such path as a string consisting of only the uppercase letters 'L', 'R', and 'U'. Each letter indicates a specific direction:

'L' means to go from a node to its left child node.
'R' means to go from a node to its right child node.
'U' means to go from a node to its parent node.
Return the step-by-step directions of the shortest path from node s to node t.

 

Example 1:


Input: root = [5,1,2,3,null,6,4], startValue = 3, destValue = 6
Output: "UURL"
Explanation: The shortest path is: 3 → 1 → 5 → 2 → 6.
Example 2:


Input: root = [2,1], startValue = 2, destValue = 1
Output: "L"
Explanation: The shortest path is: 2 → 1.
*/

class Solution {
public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        // Find the Lowest Common Ancestor (LCA) of start and destination nodes
        TreeNode* lowestCommonAncestor =
            findLowestCommonAncestor(root, startValue, destValue);

        string pathToStart;
        string pathToDest;

        // Find paths from LCA to start and destination nodes
        findPath(lowestCommonAncestor, startValue, pathToStart);
        findPath(lowestCommonAncestor, destValue, pathToDest);

        string directions;

        // Add "U" for each step to go up from start to LCA
        directions.append(pathToStart.length(), 'U');

        // Append the path from LCA to destination
        directions.append(pathToDest);

        return directions;
    }

private:
    TreeNode* findLowestCommonAncestor(TreeNode* node, int value1, int value2) {
        if (node == nullptr) return nullptr;

        if (node->val == value1 || node->val == value2) return node;

        TreeNode* leftLCA =
            findLowestCommonAncestor(node->left, value1, value2);
        TreeNode* rightLCA =
            findLowestCommonAncestor(node->right, value1, value2);

        if (leftLCA == nullptr)
            return rightLCA;
        else if (rightLCA == nullptr)
            return leftLCA;
        else
            return node;  // Both values found, this is the LCA
    }

    bool findPath(TreeNode* node, int targetValue, string& path) {
        if (node == nullptr) return false;

        if (node->val == targetValue) return true;

        // Try left subtree
        path.push_back('L');
        if (findPath(node->left, targetValue, path)) {
            return true;
        }
        path.pop_back();  // Remove last character

        // Try right subtree
        path.push_back('R');
        if (findPath(node->right, targetValue, path)) {
            return true;
        }
        path.pop_back();  // Remove last character

        return false;
    }
};

