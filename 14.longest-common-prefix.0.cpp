// CreateTime: 2021-04-01 11:24:15
class Solution {
public:
    string ans;
    string longestCommonPrefix(vector<string>& strs) {
        int len = strs.size();
        if (len == 0) {
            return "";
        }

        int k = 0;
        while (true) {
            for (int i = 0; i < strs.size(); i++) {
                if (strs[i].size() <= k) {
                    return ans;
                }
            }

            auto c = strs[0][k];
            for (int i = 1; i < strs.size(); i++) {
                if (strs[i][k] != c) {
                    return ans;
                }
            }
            ans += c;
            k++;
        }

        return "";
    }
};
