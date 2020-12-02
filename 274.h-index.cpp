// CreateTime: 2020-12-02 00:03:10
class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int len = citations.size();

        int ans = 0;
        for (int i = 0; i < len; i++) {
            if (citations[len-1-i] >= ans+1) {
                ans++;
            } else {
                break;
            }
        }
        return ans;
    }
};
