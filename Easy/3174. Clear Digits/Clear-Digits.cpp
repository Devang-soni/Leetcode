/*
You are given a string s.
Your task is to remove all digits by doing this operation repeatedly:

Delete the first digit and the closest non-digit character to its left.
Return the resulting string after removing all digits.

Example 1:
Input: s = "abc"
Output: "abc"
Explanation:

There is no digit in the string.
Example 2:

Input: s = "cb34"

Output: ""

Explanation:

First, we apply the operation on s[2], and s becomes "c4".

Then we apply the operation on s[1], and s becomes "".
*/
class Solution {
public:
    string clearDigits(string s) {
        while (true) {
            bool digitFound = false;
            for (int i = 0; i < s.length(); ++i) {
                if (isdigit(s[i])) {
                    digitFound = true;
                    int j = i - 1;
                    while (j >= 0 && isdigit(s[j])) {
                        j--;
                    }
                    if (j >= 0) {
                        s.erase(i, 1);  
                        s.erase(j, 1);  
                    } else {
                        s.erase(i, 1);  
                    }
                    break; 
                }
            }
            if (!digitFound) break; 
        }
        return s;
    }
};


