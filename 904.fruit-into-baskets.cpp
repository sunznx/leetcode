// CreateTime: 2020-11-24 21:09:00
class Solution {
public:
    int totalFruit(vector<int>& tree) {
        int ans = 0;

        int l = 0;
        int r = 0;

        unordered_map<int, int> window;

        while (r < tree.size()) {
            auto x = tree[r++];
            window[x]++;

            while (window.size() > 2) {
                auto y = tree[l++];
                window[y]--;
                if (window[y] == 0) {
                    window.erase(y);
                }
            }
            ans = max(ans, r-l);
        }

        return ans;
    }
};
