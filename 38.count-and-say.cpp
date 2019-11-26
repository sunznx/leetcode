// CreateTime: 2019-11-26 23:44:46
class Solution {
public:
    string countAndSay(int n) {
        vector<string> res(31);
        
        res[1] = "1";
        for (int i = 2; i <= n; i++) {
            int j = 0;
            int len = res[i-1].size();

            int cnt = 0;
            while (j < len || cnt) {
                if (cnt == 0 || res[i-1][j] == res[i-1][j-1]) {
                    cnt += 1;
                    j++;
                } else {
                    res[i] += to_string(cnt) + res[i-1][j-1];
                    cnt = 0;
                }
            }
        }
        
        return res[n];
    }
};