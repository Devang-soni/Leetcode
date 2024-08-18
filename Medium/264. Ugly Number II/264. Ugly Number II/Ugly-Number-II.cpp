/*

An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5.

Given an integer n, return the nth ugly number.

 

Example 1:

Input: n = 10
Output: 12
Explanation: [1, 2, 3, 4, 5, 6, 8, 9, 10, 12] is the sequence of the first 10 ugly numbers.
Example 2:

Input: n = 1
Output: 1
Explanation: 1 has no prime factors, therefore all of its prime factors are limited to 2, 3, and 5.

*/

class Solution {
public:
    int nthUglyNumber(int n)
{
    set<long long> pq;
    pq.insert(1);
    int count=0;
    while(pq.size())
    {
      int m=pq.size();
      while(m--)
      {
        long long x=*pq.begin();
        pq.erase(x);
        count++;
        if(count==n)
        {
            return x;
        }
        pq.insert(x*2);
        pq.insert(x*3);
        pq.insert(x*5);
      }
    }
    return -1;

}
};
