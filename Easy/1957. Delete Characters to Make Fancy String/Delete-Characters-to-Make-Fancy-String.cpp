/*
A fancy string is a string where no three consecutive characters are equal.

Given a string s, delete the minimum possible number of characters from s to make it fancy.

Return the final string after the deletion. It can be shown that the answer will always be unique.

 

Example 1:

Input: s = "leeetcode"
Output: "leetcode"
Explanation:
Remove an 'e' from the first group of 'e's to create "leetcode".
No three consecutive characters are equal, so return "leetcode".
Example 2:

Input: s = "aaabaaaa"
Output: "aabaa"
Explanation:
Remove an 'a' from the first group of 'a's to create "aabaaaa".
Remove two 'a's from the second group of 'a's to create "aabaa".
No three consecutive characters are equal, so return "aabaa".
Example 3:

Input: s = "aab"
Output: "aab"
Explanation: No three consecutive characters are equal, so return "aab".


*/

class Solution {
public:
    string makeFancyString(string s) {
        stack<char>st;
        for(int i = 0;i<s.length();i++){
            st.push(s[i]);
            if(st.size()>=3){
                char first = st.top();
                st.pop();
                char second = st.top();
                st.pop();
                char third = st.top();
                st.pop();
                if(first == second && second == third){
                    
                    st.push(second);
                    st.push(first);
                }else{
                    
                    st.push(third);
                    st.push(second);
                    st.push(first);
                }
            }
        }

        string ans = "";
        while(!st.empty()){
            ans += st.top();
            st.pop();

        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
