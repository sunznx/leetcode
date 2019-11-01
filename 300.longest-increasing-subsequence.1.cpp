class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len = nums.size();
        vector<int> aux(len+1, 0x3fffffff);

        int ans = 0;

        for (int i = 0; i < len; i++) {
            int l = 1;
            int r = ans + 1;
            while (l < r) {
                int mid = (l+r) / 2;
                if (aux[mid] >= nums[i]) {
                    r = mid;
                } else {
                    l = mid+1;
                }
            }
            
            aux[l] = min(aux[l], nums[i]);
            ans = max(ans, l);
        }

        return ans;
    }
};
