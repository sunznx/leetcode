// CreateTime: 2020-12-02 00:03:10
class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int len = citations.size();

        int ans = 0;
        for (int i = len-1; i >= 0; i--) {
            if (citations[i] > ans) {
                ans++;
            }
        }

        return ans;
    }
};
