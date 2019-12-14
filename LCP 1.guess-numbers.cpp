// CreateTime: 2019-12-13 19:17:16
class Solution {
public:
    int game(vector<int>& guess, vector<int>& answer) {
        int ans = 0;
        
        if (guess[0] == answer[0]) {
            ans += 1;
        }
        if (guess[1] == answer[1]) {
            ans += 1;
        }
        if (guess[2] == answer[2]) {
            ans += 1;
        }

        return ans;
    }
};
