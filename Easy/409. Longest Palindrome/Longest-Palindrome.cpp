/*
Given a string s which consists of lowercase or uppercase letters, return the length of the longest 
palindrome
 that can be built with those letters.

Letters are case sensitive, for example, "Aa" is not considered a palindrome.

 

Example 1:

Input: s = "abccccdd"
Output: 7
Explanation: One longest palindrome that can be built is "dccaccd", whose length is 7.
Example 2:

Input: s = "a"
Output: 1
Explanation: The longest palindrome that can be built is "a", whose length is 1.
*/


class Solution {
public:
    int longestPalindrome(string s) {
        int n=s.length();
        unordered_set<char> st;
        int result = 0;

        for(char &ch:s){
            if(st.count(ch)){
                result += 2;
                st.erase(ch);
            }
            else{
                st.insert(ch);
            }
        }

        if(!st.empty()){
            result++;
        }
        return result;

    }
};
