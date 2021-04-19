// CreateTime: 2021-04-18 10:24:53
class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int> m(256);
        for (auto &x: sentence) {
            m[x]++;
        }

        for (int c = 'a'; c <= 'z'; c++) {
            if (m[c] == 0) {
                return false;
            }
        }
        return true;
    }
};