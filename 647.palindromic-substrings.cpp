class Solution {
public:
    int countSubstrings(string s) {
        int len = s.size();
        vector<vector<int>> dp(len+1, vector<int>(len+1, 0));
        vector<vector<int>> isPalindromic(len+1, vector<int>(len+1, 0));

        int ans = len;
        for (int i = 0; i < len; i++) {
            isPalindromic[i][i] = 1;
        }

        for (int l = 2; l <= len; l++) {
            for (int i = len-l; i >= 0; i--) {
                int j = i+l-1;

                if (s[i] == s[j]) {
                    if (l == 2) {
                        ans += 1;
                        isPalindromic[i][j] = 1;
                    } else {
                        if (isPalindromic[i+1][j-1]) {
                            ans += 1;
                            isPalindromic[i][j] = 1;
                        }
                    }
                }
            }
        }

        return ans;
    }
};
