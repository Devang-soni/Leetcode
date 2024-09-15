/*
Given the string s, return the size of the longest substring containing each vowel an even number of times. That is, 'a', 'e', 'i', 'o', and 'u' must appear an even number of times.

 

Example 1:

Input: s = "eleetminicoworoep"
Output: 13
Explanation: The longest substring is "leetminicowor" which contains two each of the vowels: e, i and o and zero of the vowels: a and u.
Example 2:

Input: s = "leetcodeisgreat"
Output: 5
Explanation: The longest substring is "leetc" which contains two e's.
Example 3:

Input: s = "bcbcbc"
Output: 6
Explanation: In this case, the given string "bcbcbc" is the longest because all vowels: a, e, i, o and u appear zero times.

*/

class Solution {
public:
    int findTheLongestSubstring(string s) {
        unordered_map<int, int> mp;
        mp[0] = -1;
        int mask = 0;
        int maxL = 0;
        for(int i = 0; i<s.length(); i++) {
            int val = 0;
            if (s[i] == 'a')      val  = (1 << 0);
            else if (s[i] == 'e') val = (1 << 1);
            else if (s[i] == 'i') val = (1 << 2);
            else if (s[i] == 'o') val = (1 << 3);
            else if (s[i] == 'u') val = (1 << 4);
            
            mask = mask^val; //xor nikala
            
            if(!mp.count(mask)) //agar past me nahi dekha to map me daaldo
                mp[mask] = i;
            
            maxL = max(maxL, i - mp[mask]); //maxL nikaal lo
        }
        return maxL;
    }
};

