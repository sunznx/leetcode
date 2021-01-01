// CreateTime: 2021-01-01 10:58:22
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int len = flowerbed.size();

        int ans = 0;
        for (int i = 0; i < len; i++) {
            auto &x = flowerbed[i];
            if (x == 0 &&
                (i-1 >= 0 && flowerbed[i-1] == 0 || i == 0) &&
                (i+1 <= len-1 && flowerbed[i+1] == 0 || i == len-1)) {
                x = 1;
                ans++;
            }
        }

        return ans >= n;
    }
};
