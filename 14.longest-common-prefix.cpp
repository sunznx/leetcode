class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int len = strs.size();

        if (len == 0) {
            return "";
        }
        if (len == 1) {
            return strs[0];
        }

        int index = -1;
        string res = "";
        bool ok = true;
        while (ok) {
            for (int i = 1; i < len; i++) {
                if (strs[i].size() <= index+1 || strs[i][index+1] != strs[0][index+1]) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                index += 1;
            }
        }

        for (int i = 0; i <= index; i++) {
            res += strs[0][i];
        }

        return res;
    }
};
