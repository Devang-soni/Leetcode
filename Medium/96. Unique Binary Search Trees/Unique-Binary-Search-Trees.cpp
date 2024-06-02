/*
Given an integer n, return the number of structurally unique BST's (binary search trees) which has exactly n nodes of unique values from 1 to n.

*/

class Solution {
    double fact(int n) {
        double ans = 1;
        for (int i = 1; i <= n; i++) {
            ans = ans * i;
        }
        return ans;
    }

public:
    int numTrees(int n) {
        double h = fact(2 * n) / (fact(n) * fact(n + 1));  // Corrected the formula
        return static_cast<int>(h+0.5);
    }
};
