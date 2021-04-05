// CreateTime: 2021-04-05 09:36:58
class Solution {
public:
    int numRabbits(vector<int>& answers) {
        sort(answers.rbegin(), answers.rend());

        int ans = 0;
        int k = 0;
        int len = answers.size();
        while (k < len) {
            ans += answers[k]+1;

            int d = 1;
            while (k+d < len && d <= answers[k] && answers[k+d] == answers[k]) {
                d++;
            }
            k += d;
        }
        return ans;
    }
};
