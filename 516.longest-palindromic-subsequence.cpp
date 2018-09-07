class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int len = s.size();

        vector<vector<int>> dp(len, vector<int>(len, 0));

        for (int i = len-1; i >= 0; i--) {
            dp[i][i] = 1;
            for (int j = i+1; j < len; j++) {
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i+1][j-1] + 2;
                } else {
                    dp[i][j] = max(dp[i][j-1], dp[i+1][j]);
                }
            }
        }

        return dp[0][len-1];
    }
};

// class Solution {
// public:
//     int longestPalindromeSubseq(string s) {
//         return longestPalindromeSubseq(s, 0, s.size()-1);
//     }
// 
//     int longestPalindromeSubseq(string s, int l, int r) {
//         if (l > r) {
//             return 0;
//         }
// 
//         if (s[l] == s[r]) {
//             if (l == r) {
//                 return longestPalindromeSubseq(s, l+1, r-1) + 1;
//             } else {
//                 return longestPalindromeSubseq(s, l+1, r-1) + 2;
//             }
//         } else {
//             return max(longestPalindromeSubseq(s, l+1, r),
//                        longestPalindromeSubseq(s, l, r-1));
//         }
//     }
// };
