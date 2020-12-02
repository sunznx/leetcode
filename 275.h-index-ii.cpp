// CreateTime: 2020-12-01 23:58:49
class Solution {
public:
    int hIndex(vector<int>& citations) {
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
