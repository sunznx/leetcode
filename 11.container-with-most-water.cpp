// CreateTime: 2021-04-03 14:50:05
class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0;

        int len = height.size();
        int l = 0;
        int r = len-1;

        while (l != r) {
            int val = min(height[l], height[r]) * (r-l);
            ans = max(ans, val);

            if (height[l] < height[r]) {
                l++;
            } else {
                r--;
            }
        }
        return ans;
    }
};
