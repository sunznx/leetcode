// CreateTime: 2021-04-02 10:34:44
class Solution {
public:
    int trap(vector<int>& height) {
        int len = height.size();

        vector<int> maxL(len);
        vector<int> maxR(len);

        for (int i = 1; i < len; i++) {
            maxL[i] = max(maxL[i-1], height[i-1]);
        }

        for (int i = len-2; i >=0; i--) {
            maxR[i] = max(maxR[i+1], height[i+1]);
        }

        int ans = 0;
        for (int i = 0; i < len; i++) {
            ans += max(0, min(maxL[i], maxR[i]) - height[i]);
        }
        return ans;
    }
};
