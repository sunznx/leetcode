// CreateTime: 2020-12-02 08:55:38
class Solution {
public:
    string smallestSubsequence(string s) {
        int len = s.size();

        vector<int> pos(256);        // x 最后一次出现的位置
        vector<bool> seen(256);

        for (int i = 0; i < len; i++) {
            auto x = s[i];
            pos[x] = i;
        }

        string ans;
        for (int i = 0; i < len; i++) {
            auto x = s[i];
            if (!seen[x]) {
                while (ans.size() && pos[ans.back()] > i && x < ans.back()) {
                    seen[ans.back()] = false;
                    ans.pop_back();
                }
                seen[x] = true;
                ans.push_back(x);
            }
        }

        return ans;
    }
};
