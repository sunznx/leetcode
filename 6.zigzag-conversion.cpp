// P   A   H   N
// A P L S I I G
// Y   I   R

// CreateTime: 2019-12-05 15:20:21
class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> v(numRows);

        int k = 0;
        int len = s.size();
        int dir = 0;

        while (k < len) {
            if (dir == 0) {
                for (int i = 0; i < numRows && k < len; i++) {
                    v[i].push_back(s[k++]);
                }
            } else {
                for (int i = numRows-2; i >= 1 && k < len; i--) {
                    v[i].push_back(s[k++]);
                }
            }
            dir = 1 - dir;
        }

        string res = "";
        for (int i = 0; i < numRows; i++) {
            res = res + v[i];
        }

        return res;
    }
};
