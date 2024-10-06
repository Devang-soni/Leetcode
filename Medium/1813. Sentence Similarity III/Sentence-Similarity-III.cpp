/*
You are given two strings sentence1 and sentence2, each representing a sentence composed of words. A sentence is a list of words that are separated by a single space with no leading or trailing spaces. Each word consists of only uppercase and lowercase English characters.

Two sentences s1 and s2 are considered similar if it is possible to insert an arbitrary sentence (possibly empty) inside one of these sentences such that the two sentences become equal. Note that the inserted sentence must be separated from existing words by spaces.

For example,

s1 = "Hello Jane" and s2 = "Hello my name is Jane" can be made equal by inserting "my name is" between "Hello" and "Jane" in s1.
s1 = "Frog cool" and s2 = "Frogs are cool" are not similar, since although there is a sentence "s are" inserted into s1, it is not separated from "Frog" by a space.
Given two sentences sentence1 and sentence2, return true if sentence1 and sentence2 are similar. Otherwise, return false.

 

Example 1:

Input: sentence1 = "My name is Haley", sentence2 = "My Haley"

Output: true

Explanation:

sentence2 can be turned to sentence1 by inserting "name is" between "My" and "Haley".

Example 2:

Input: sentence1 = "of", sentence2 = "A lot of words"

Output: false

Explanation:

No single sentence can be inserted inside one of the sentences to make it equal to the other.

Example 3:

Input: sentence1 = "Eating right now", sentence2 = "Eating"

Output: true

Explanation:

sentence2 can be turned to sentence1 by inserting "right now" at the end of the sentence.

*/

class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
    
    vector<string> s1;
    vector<string> s2;

    sentence1.push_back(' ');
    sentence2.push_back(' ');

    string ans = "";

    for(int i=0; i<sentence1.size(); i++)
    {
        if(sentence1[i] == ' ')
        {
            s1.push_back(ans); 
            ans = "";
        }
        else
        {
            ans.push_back(sentence1[i]);
        }
    }
        for(int i = 0; i<sentence2.size(); i++)
        {
            if(sentence2[i] == ' ')
            {
                s2.push_back(ans);
                ans = "";
            }
            else
            {
                ans.push_back(sentence2[i]);
            }
        }
   
       int m1 = 0, m2 = 0;
       int n1 = s1.size() - 1, n2 = s2.size() - 1;

       while(m1 <= n1 && m2 <= n2)
       {
        if(s1[m1] == s2[m2])
        {
            m1++;
            m2++;
        }
        else if(s1[n1] == s2[n2])
        {
            n1--;
            n2--;
        }
        else break;
       
       }
    
 
      return(n1 + 1 == m1 || n2 +1 == m2) ? true:false;

    }
};

