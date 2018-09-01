class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> aux = nums;
        sort(aux.begin(), aux.end());

        int len1 = nums.size();
        int len2 = aux.size();
        vector<vector<int>> dp(len1+1, vector<int>(len2+1, 0));
        
        for (int i = 0; i < len1; i++) {
            for (int j = 0; j < len2; j++) {
                if (j > 0 && aux[j] == aux[j-1]) {
                    dp[i+1][j+1] = dp[i+1][j];
                } else if (nums[i] == aux[j]) {
                    dp[i+1][j+1] = dp[i][j] + 1;
                } else {
                    dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
                }
            }
        }
        
        return dp[len1][len2];
    }
};
