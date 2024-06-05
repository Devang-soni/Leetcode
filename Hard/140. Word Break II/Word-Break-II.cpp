/*
Given a string s and a dictionary of strings wordDict, add spaces in s to construct a sentence where each word is a valid dictionary word. Return all such possible sentences in any order.

Note that the same word in the dictionary may be reused multiple times in the segmentation.
Example 1:

Input: s = "catsanddog", wordDict = ["cat","cats","and","sand","dog"]
Output: ["cats and dog","cat sand dog"]
Example 2:

Input: s = "pineapplepenapple", wordDict = ["apple","pen","applepen","pine","pineapple"]
Output: ["pine apple pen apple","pineapple pen apple","pine applepen apple"]
Explanation: Note that you are allowed to reuse a dictionary word.
*/
class Solution {
    vector<string> ans;

    void helper(string &s, int i, string sentence, unordered_map<string,int>& dict) {
        if (i >= s.size()) {
            if (sentence.back() == ' ')
                sentence.pop_back();
            ans.push_back(sentence);
            return;
        }
        string temp = "";
        for (int j=i; j<s.size(); j++) {
            temp.push_back(s[j]);
 
            if (dict.find(temp) != dict.end()) { 
                helper(s, j+1, sentence+temp+' ', dict);
            }
        }
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {

        unordered_map<string, int> dict; 
        for (auto s0: wordDict)
            dict[s0]++;

        helper(s, 0, "", dict);
        return ans;
    }
};
