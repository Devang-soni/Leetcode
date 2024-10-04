/*
You are given a positive integer array skill of even length n where skill[i] denotes the skill of the ith player. Divide the players into n / 2 teams of size 2 such that the total skill of each team is equal.

The chemistry of a team is equal to the product of the skills of the players on that team.

Return the sum of the chemistry of all the teams, or return -1 if there is no way to divide the players into teams such that the total skill of each team is equal.

 

Example 1:

Input: skill = [3,2,5,1,3,4]
Output: 22
Explanation: 
Divide the players into the following teams: (1, 5), (2, 4), (3, 3), where each team has a total skill of 6.
The sum of the chemistry of all the teams is: 1 * 5 + 2 * 4 + 3 * 3 = 5 + 8 + 9 = 22.
Example 2:

Input: skill = [3,4]
Output: 12
Explanation: 
The two players form a team with a total skill of 7.
The chemistry of the team is 3 * 4 = 12.
Example 3:

Input: skill = [1,1,2,3]
Output: -1
Explanation: 
There is no way to divide the players into teams such that the total skill of each team is equal.

*/

class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(), skill.end());

        int n = skill.size();
        long long totalChemistry = 0;

        // Calculate the target sum
        int i = 0, j = n-1;
        int targetTeamSkill = skill[i] + skill[j];

        // Iterate through half of the array, pairing players from both ends
        while (i < j) {
            int currentTeamSkill = skill[i] + skill[j];

            // If any team's skill doesn't match the target, return -1
            if (currentTeamSkill != targetTeamSkill) {
                return -1;
            }

            // Calculate and add the chemistry of the current team
            totalChemistry += (long long)skill[i] * (long long)skill[j];
            i++;
            j--;
        }

        return totalChemistry;
    }
};
