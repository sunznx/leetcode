// CreateTime: 2020-11-30 08:00:53
class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int ans = 0;

        queue<int> que;

        for (int i = 0; i < s.size(); i++) {
            auto x1 = s[i];
            auto x2 = t[i];
            auto cost = abs(x1-x2);

            while (que.size() && maxCost < cost) {
                auto front = que.front();
                que.pop();
                maxCost += front;
            }

            if (maxCost >= cost) {
                maxCost -= cost;
                que.push(cost);
            }

            ans = max(ans, (int)(que.size()));
        }

        return ans;
    }
};
