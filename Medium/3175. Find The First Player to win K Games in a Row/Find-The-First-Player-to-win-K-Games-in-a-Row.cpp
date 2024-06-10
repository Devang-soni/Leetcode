


class Solution {
public:
    int findWinningPlayer(vector<int>& skills, int k) {
        int n = skills.size();
        
        int max_skill = *max_element(skills.begin(), skills.end());
        
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            q.push(i);
        }
        
        int current_winner = q.front();
        q.pop();
        int win_count = 0;
        
        while (true) {
            int challenger = q.front();
            q.pop();
            
            if (skills[current_winner] > skills[challenger]) {
                ++win_count;
                q.push(challenger);  
            } else {
                q.push(current_winner);  
                current_winner = challenger;
                win_count = 1;
            }
            
            if (win_count == k) {
                return current_winner;
            }
            
            if (skills[current_winner] == max_skill) {
                return current_winner;
            }
        }
    }
};
