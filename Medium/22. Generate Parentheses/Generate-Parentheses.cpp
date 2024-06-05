/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
Example 2:

Input: n = 1
Output: ["()"]
*/
class Solution {
public:
    vector<string> ans;
    void f(int n,string s ,int a,int b)
    {
        if(a+b == 2*n)
        {
            ans.push_back(s);
            return ;
        }
        if(a+1<=n)
        {
            f(n,s+'(',a+1,b);
        }
        if(b+1<=n && b+1<=a)
        {
            f(n,s+')',a,b+1);
        }
    }
    vector<string> generateParenthesis(int n) {
      string s;
        f(n,s,0,0);
        return ans;
    }
};
