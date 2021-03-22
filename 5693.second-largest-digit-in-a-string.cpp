// CreateTime: 2021-03-20 22:34:37
class Solution {
public:
    int secondHighest(string s) {
        vector<bool> seen(256);
        for (auto &x: s) {
            seen[x] = true;
        }

        bool isFirst = true;
        for (char x = '9'; x >= '0'; x--) {
            if (isFirst == true && seen[x]) {
                isFirst = false;
            } else if (isFirst == false && seen[x]) {
                return x - '0';
            }
        }
        return -1;
    }
};