/*
Convert a non-negative integer num to its English words representation.

 

Example 1:

Input: num = 123
Output: "One Hundred Twenty Three"
Example 2:

Input: num = 12345
Output: "Twelve Thousand Three Hundred Forty Five"
Example 3:

Input: num = 1234567
Output: "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
 
*/

class Solution {
public:
    vector<string> belowTen = {"","One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    vector<string> belowTwenty = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    vector<string> belowHundred = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    string numberToWords(int num) {
        if(num == 0)
           return "Zero";
        return find(num);
    }

    string find(int num)
    {
        string result = "";
        if(num<10)
            result = belowTen[num];
        else
            if(num<20)
                result = belowTwenty[num-10];
        else
            if(num<100)
                result = belowHundred[num/10] + " " + find(num%10);
        else
            if(num<1000)
                result = find(num/100) + " Hundred " + find(num%100);
        else
            if(num<1000000)
                result = find(num/1000) + " Thousand " + find(num%1000);
        else
            if(num<1000000000)
                result = find(num/1000000) + " Million " + find(num%1000000);
        else
            result = find(num/1000000000) + " Billion " + find(num%1000000000);
        int size = result.length();
        if(size>0 && result[size-1]==' ')
            result = result.substr(0, size-1);
        return result;
    }
};


