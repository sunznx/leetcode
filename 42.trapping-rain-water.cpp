class Solution {
public:
    struct node {
        int maxL = 0;
        int maxR = 0;
    };

    int trap(vector<int>& height) {
        int len = height.size();

        vector<node> aux(len);

        int maxL = 0;
        for (int i = 0; i < len; i++) {
            aux[i].maxL = maxL;
            maxL = max(maxL, height[i]);
        }
        
        int maxR = 0;
        for (int i = len-1; i >= 0; i--) {
            aux[i].maxR = maxR;
            maxR = max(maxR, height[i]);
        }
        
        int ans = 0;
        for (int i = 0; i < len; i++) {
            ans += max(0, min(aux[i].maxL, aux[i].maxR) - height[i]);
        }
        
        return ans;
    }
};
