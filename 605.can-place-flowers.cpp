class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int len = flowerbed.size();
        vector<bool> v(len+1, false);
        for (int i = 0; i < len; i++) {
            if (flowerbed[i] == 1) {
                v[i] = true;
                if (i != 0) {
                    v[i-1] = true;
                }
                if (i != len-1) {
                    v[i+1] = true;
                }
            }
        }

        int res = 0;
        for (int i = 0; i < len; i++) {
            if (!(flowerbed[i] == 1 || v[i] == true)) {
                v[i+1] = true;
                res++;
            }
        }

        return res >= n;
    }
};
