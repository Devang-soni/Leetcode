/*
There is a strange printer with the following two special properties:

The printer can only print a sequence of the same character each time.
At each turn, the printer can print new characters starting from and ending at any place and will cover the original existing characters.
Given a string s, return the minimum number of turns the printer needed to print it.

 

Example 1:

Input: s = "aaabbb"
Output: 2
Explanation: Print "aaa" first and then print "bbb".
Example 2:

Input: s = "aba"
Output: 2
Explanation: Print "aaa" first and then print "b" from the second place of the string, which will cover the existing character 'a'.
 
*/

class Solution {
public:
    int solve(string &s, int i, int j,vector<vector<int>> &dp){
        if(i>j) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int ans = solve(s,i,j-1,dp)+1;

        for(int k=i;k<j;k++){
            if(s[k]==s[j])
                ans=min(ans,solve(s,i,k,dp)+solve(s,k+1,j-1,dp));
        }

        return dp[i][j]=ans;
    }
    int strangePrinter(string s) {
        int n = s.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

        return solve(s,0,n-1,dp);
    }
};
