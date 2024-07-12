/*
You are given a string s and two integers x and y. You can perform two types of operations any number of times.

Remove substring "ab" and gain x points.
For example, when removing "ab" from "cabxbae" it becomes "cxbae".
Remove substring "ba" and gain y points.
For example, when removing "ba" from "cabxbae" it becomes "cabxe".
Return the maximum points you can gain after applying the above operations on s.

 

Example 1:

Input: s = "cdbcbbaaabab", x = 4, y = 5
Output: 19
Explanation:
- Remove the "ba" underlined in "cdbcbbaaabab". Now, s = "cdbcbbaaab" and 5 points are added to the score.
- Remove the "ab" underlined in "cdbcbbaaab". Now, s = "cdbcbbaa" and 4 points are added to the score.
- Remove the "ba" underlined in "cdbcbbaa". Now, s = "cdbcba" and 5 points are added to the score.
- Remove the "ba" underlined in "cdbcba". Now, s = "cdbc" and 5 points are added to the score.
Total score = 5 + 4 + 5 + 5 = 19.
Example 2:

Input: s = "aabbaaxybbaabb", x = 5, y = 4
Output: 20
*/

class Solution {
public:
bool op(string &s,char c1,char c2,int p,int &ans){
    string h="";
    bool k=0;
    for(auto it:s){
    h+=it; 
    if(h.size()>1 and h[h.size()-1]==c2 and h[h.size()-2]==c1){
    h.pop_back();
    h.pop_back();
    ans+=p; 
    k=1;
    }
    }
    s=h;
    return k;
}
    int maximumGain(string s, int x, int y) {
    bool k=1;
    char c1='a',c2='b';
    if(x<y) swap(c1,c2);
    string h="";
    int ans=0;
    while(k){  
        k=op(s,c1,c2,max(x,y),ans);
        k=k | op(s,c2,c1,min(x,y),ans);
    }
    return ans;   
    }
};
