/*
You are given two strings s and t consisting of only lowercase English letters.

Return the minimum number of characters that need to be appended to the end of s so that t becomes a subsequence of s.

A subsequence is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters.
*/

class Solution {
public:
    int appendCharacters(string s, string t) {
     int n = s.size();
     int m = t.size();
     int j = 0;
     for(int i = 0;i<n;i++){
        if(s[i] == t[j])
            j++;
     
        if(j == m) return 0;
    }
    return m-j;}
};
