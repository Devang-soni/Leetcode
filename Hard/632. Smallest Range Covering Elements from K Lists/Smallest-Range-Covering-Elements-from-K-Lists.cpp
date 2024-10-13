/*
You have k lists of sorted integers in non-decreasing order. Find the smallest range that includes at least one number from each of the k lists.

We define the range [a, b] is smaller than range [c, d] if b - a < d - c or a < c if b - a == d - c.

 

Example 1:

Input: nums = [[4,10,15,24,26],[0,9,12,20],[5,18,22,30]]
Output: [20,24]
Explanation: 
List 1: [4, 10, 15, 24,26], 24 is in range [20,24].
List 2: [0, 9, 12, 20], 20 is in range [20,24].
List 3: [5, 18, 22, 30], 22 is in range [20,24].
Example 2:

Input: nums = [[1,2,3],[1,2,3],[1,2,3]]
Output: [1,1]

*/
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();
        // Stores the current index of each list
        vector<int> indices(k, 0);
        // To track the smallest range
        vector<int> range = {-1000000, 1000000};

        while (true) {
            int curMin = INT_MAX, curMax = INT_MIN, minListIndex = 0;

            // Find the current minimum and maximum values across the lists
            for (int i = 0; i < k; i++) {
                int currentElement = nums[i][indices[i]];

                // Update the current minimum
                if (currentElement < curMin) {
                    curMin = currentElement;
                    minListIndex = i;
                }

                // Update the current maximum
                if (currentElement > curMax) {
                    curMax = currentElement;
                }
            }

            // Update the range if a smaller one is found
            if (curMax - curMin < range[1] - range[0]) {
                range[0] = curMin;
                range[1] = curMax;
            }

            // Move to the next element in the list that had the minimum value
            if (++indices[minListIndex] == nums[minListIndex].size()) break;
        }

        return range;
    }
};

