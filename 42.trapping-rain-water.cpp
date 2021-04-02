// CreateTime: 2021-04-02 10:34:44
class Solution {
public:
    int trap(vector<int>& height) {
        int len = height.size();

        vector<int> maxL(len);
        vector<int> maxR(len);

        int val;

        val = 0;
        for (int i = 0; i < len; i++) {
            val = max(val, height[i]);
            maxL[i] = val;
        }

        val = 0;
        for (int i = len-1; i >=0; i--) {
            val = max(val, height[i]);
            maxR[i] = val;
        }

        int ans = 0;
        for (int i = 0; i < len; i++) {
            ans += max(0, min(maxL[i], maxR[i]) - height[i]);
        }
        return ans;
    }
};
