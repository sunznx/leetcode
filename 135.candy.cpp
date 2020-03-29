// CreateTime: 2020-03-29 19:05:29
class Solution {
public:
    int candy(vector<int>& ratings) {
        auto len = ratings.size();

        vector<int> v1(len, 1);
        vector<int> v2(len, 1);

        for (int i = 1; i < len; i++) {
            if (ratings[i] > ratings[i-1]) {
                v1[i] = v1[i-1] + 1;
            }
        }

        for (int i = len-2; i >= 0; i--) {
            if (ratings[i] > ratings[i+1]) {
                v2[i] = v2[i+1] + 1;
            }
        }

        int ans = 0;
        for (int i = 0; i < len; i++) {
            ans += max(v1[i], v2[i]);
        }
        return ans;
    }
};