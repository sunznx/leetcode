class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int index = 0;
        string res = "";

        while (strs.size() > 0 && index < strs[0].size()) {
            for (int i = 1; i < strs.size(); i++) {
                if (index >= strs[i].size() || strs[i][index] != strs[0][index]) {
                    return res;
                }
            }
            res = res + strs[0][index];
            index += 1;
        }

        return res;
    }
};
