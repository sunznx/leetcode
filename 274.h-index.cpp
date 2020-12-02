// CreateTime: 2020-12-02 00:03:10
class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.rbegin(), citations.rend());

        int ans = 0;
        for (int i = 0; i < citations.size(); i++) {
            auto x = citations[i];
            if (x > ans) {
                ans++;
            }
        }

        return ans;
    }
};
