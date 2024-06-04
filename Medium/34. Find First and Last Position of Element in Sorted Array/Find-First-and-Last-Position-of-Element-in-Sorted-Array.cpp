/*
Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]

*/
class Solution {
public:
    int getFirst(vector<int>& nums, int target){
        int s=0;
        int e =nums.size()-1;
        int ans = -1;
        while(s<=e){
            int mid = s + (e-s)/2;

            if(nums[mid] == target){
                ans = mid;//searching in LHS
                e = mid-1;
                //return mid;
            }
            else if( nums[mid] < target){
                s = mid+1;
            }
            else{
                e = mid-1;
            }
        }
        return ans;
    }

    int getLast(vector<int>& nums, int target){
        int s=0;
        int e =nums.size()-1;
        int ans = -1;
        while(s<=e){
            int mid = s + (e-s)/2;

            if(nums[mid] == target){
                ans = mid; //Searching in RHS
                s = mid+1;
                //return mid;
            }
            else if( nums[mid] < target){
                s = mid+1;
            }
            else{
                e = mid-1;
            }
        }
        return ans;
    }


    vector<int> searchRange(vector<int>& nums, int target) {
        
        vector<int> v(2,-1);
        int first = getFirst(nums,target);
        if(first == -1){
            return v;
        }
        int last = getLast(nums,target);
        v[0] = first;
        v[1] = last;

        return v;
    }
};
