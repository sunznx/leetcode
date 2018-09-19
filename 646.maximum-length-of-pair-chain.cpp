class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int len = pairs.size();
        if (len == 0) {
            return 0;
        }

        sort(pairs.begin(), pairs.end(), [](auto const &a, auto const &b) {
                                             return a[1] < b[1];
                                         });

        int ans = 1;
        int last = pairs[0][1];
        for (int i = 1; i < len; i++) {
            if (pairs[i][0] > last) {
                last = pairs[i][1];
                ans += 1;
            }
        }

        return ans;
    }
};





