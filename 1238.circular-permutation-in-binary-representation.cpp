// CreateTime: 2021-01-19 02:13:36
class Solution {
public:
    int p = 0;
    vector<int> ans;

    vector<int> circularPermutation(int n, int start) {
        for (int i = 0; i < (1<<n); i++) {
            auto x = (i^(i>>1));
            ans.push_back(x);

            if (x == start) {
                p = i;
            }
        }

        reverse(ans.begin(), ans.begin()+p);
        reverse(ans.begin()+p, ans.end());
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
