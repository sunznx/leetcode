// CreateTime: 2020-11-22 16:14:20
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int len = s2.size();

        unordered_map<char, int> need;
        for (auto &c: s1) {
            need[c]++;
        }

        unordered_map<char, int> window;

        int needCount = need.size();
        int validCount = 0;

        int left = 0;
        int right = 0;

        while (right < s2.size()) {
            char c = s2[right++];
            window[c]++;

            if (need[c] > 0 && window[c] == need[c]) {
                validCount++;
            }

            while (right - left >= s1.size()) {
                if (validCount == needCount) {
                    return true;
                }

                char d = s2[left++];
                if (need[d] && window[d] == need[d]) {
                    validCount--;
                }
                window[d]--;
            }
        }

        return false;
    }
};
