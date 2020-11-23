// CreateTime: 2020-11-23 08:11:59
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int len = s.size();

        unordered_map<char, int> window;
        unordered_map<char, int> need;

        for (auto &c: p) {
            need[c]++;
        }

        int needCount = need.size();

        int left = 0;
        int right = 0;

        int validCount = 0;

        vector<int> ans;

        while (right < len) {
            char c = s[right++];
            window[c]++;

            if (need[c] > 0 && window[c] == need[c]) {
                validCount++;
                if (validCount == needCount) {
                    ans.push_back(left);
                }
            }

            if (right-left == p.size()) {
                char d = s[left++];
                if (need[d] > 0 && window[d] == need[d]) {
                    validCount--;
                }
                window[d]--;
            }
        }

        return ans;
    }
};