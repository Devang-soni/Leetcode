/*
A boolean expression is an expression that evaluates to either true or false. It can be in one of the following shapes:

't' that evaluates to true.
'f' that evaluates to false.
'!(subExpr)' that evaluates to the logical NOT of the inner expression subExpr.
'&(subExpr1, subExpr2, ..., subExprn)' that evaluates to the logical AND of the inner expressions subExpr1, subExpr2, ..., subExprn where n >= 1.
'|(subExpr1, subExpr2, ..., subExprn)' that evaluates to the logical OR of the inner expressions subExpr1, subExpr2, ..., subExprn where n >= 1.
Given a string expression that represents a boolean expression, return the evaluation of that expression.

It is guaranteed that the given expression is valid and follows the given rules.

 

Example 1:

Input: expression = "&(|(f))"
Output: false
Explanation: 
First, evaluate |(f) --> f. The expression is now "&(f)".
Then, evaluate &(f) --> f. The expression is now "f".
Finally, return false.
Example 2:

Input: expression = "|(f,f,f,t)"
Output: true
Explanation: The evaluation of (false OR false OR false OR true) is true.
Example 3:

Input: expression = "!(&(f,t))"
Output: true
Explanation: 
First, evaluate &(f,t) --> (false AND true) --> false --> f. The expression is now "!(f)".
Then, evaluate !(f) --> NOT false --> true. We return true.
 
*/

class Solution {
public:
    bool andd(string exp){
        int n = exp.length(), j=0;
        string subexp;
        int active = 0;
        while(j<n){
            if(active == 0 && exp[j]==','){
                if(!parseBoolExpr(subexp)) return false;
                subexp = "";
                j++;
                continue;
            }
            if(exp[j]=='(') active++;
            if(exp[j]==')') active--;
            subexp += exp[j++];
        }
        if(!parseBoolExpr(subexp)) return false;
        return true;
    }

    bool orr(string exp){
        int n = exp.length(), j=0;
        string subexp;
        int active = 0;
        while(j<n){
            if(active==0 && exp[j]==','){
                if(parseBoolExpr(subexp)) return true;
                subexp = "";
                j++;
                continue;
            }
            if(exp[j]=='(') active++;
            if(exp[j]==')') active--;
            subexp += exp[j++];
        }
        if(parseBoolExpr(subexp)) return true;
        return false;
    }

    bool parseBoolExpr(string exp) {
        int n = exp.length();
        if(n==1) return (exp[0]=='t');
        if(exp[0] == '!') return !parseBoolExpr(exp.substr(2, n-3));
        if(exp[0] == '&') return andd(exp.substr(2, n-3));
        if(exp[0] == '|') return orr(exp.substr(2, n-3));
        return false;
    }
};
