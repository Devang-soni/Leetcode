/*
Given a sorted integer array nums and an integer n, add/patch elements to the array such that any number in the range [1, n] inclusive can be formed by the sum of some elements in the array.

Return the minimum number of patches required.

Example 1:

Input: nums = [1,3], n = 6
Output: 1
Explanation:
Combinations of nums are [1], [3], [1,3], which form possible sums of: 1, 3, 4.
Now if we add/patch 2 to nums, the combinations are: [1], [2], [3], [1,3], [2,3], [1,2,3].
Possible sums are 1, 2, 3, 4, 5, 6, which now covers the range [1, 6].
So we only need 1 patch.
Example 2:

Input: nums = [1,5,10], n = 20
Output: 2
Explanation: The two patches can be [2, 4].
Example 3:

Input: nums = [1,2,2], n = 5
Output: 0
*/
class Solution {
public:
    int minPatches(vector<int>& nums, int target) {
        long int max = 0;
        int numsAdded = 0, n, l = nums.size();
        for(int i=0;i<l;i++)
        {
            n = nums[i];
            while(n > max+1)    // O(LogT)
            {
                max+=max+1;     // add no which is 1 greater than last max number we can create till now
                numsAdded++;    // increament count as we just added a new number
                if(target<max)
                    return numsAdded;
            }
            max+=n;             // add num present in array to max to get next point till where we can create numbe
            if(target<max) return numsAdded;
        }
        while(target > max)     // O(LogT)
        {
            max+=max+1;
            numsAdded++;
        }
        return numsAdded;
    }
};

