class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> aux = nums;
        sort(aux.begin(), aux.end());

        int len = nums.size();
        vector<vector<int>> dp(len+1, vector<int>(len+1, 0));
        
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < len; j++) {
                if (nums[i] == aux[j] && (j == 0 || j > 0 && aux[j] != aux[j-1])) {
                    dp[i+1][j+1] = dp[i][j] + 1;
                } else {
                    dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
                }
            }
        }
        
        return dp[len][len];
    }
};
