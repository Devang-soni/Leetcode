/*
Given an integer n, return all the numbers in the range [1, n] sorted in lexicographical order.

You must write an algorithm that runs in O(n) time and uses O(1) extra space. 

 

Example 1:

Input: n = 13
Output: [1,10,11,12,13,2,3,4,5,6,7,8,9]
Example 2:

Input: n = 2
Output: [1,2]

*/

class Solution {
public:
    void helper(int i,int n,vector<int> &ans)
    {
        if(i>n) return;
        ans.push_back(i);

        for(int j=0;j<=9;j++)
        {
            int num=i*10+j;
            helper(num,n,ans);
        }
    }
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        for(int i=1;i<=9;i++)
        {
            helper(i,n,ans);
        }
        return ans;
    }
};
