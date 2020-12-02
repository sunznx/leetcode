// CreateTime: 2020-12-01 23:58:49
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int len = citations.size();
        if (len == 0) {
            return 0;
        }

        int l = 0;
        int r = len-1;

        while (l < r) {
            int m = (l+r+1) / 2;
            if (citations[len-1-m] >= m+1) {
                l = m;
            } else if (citations[len-1-m] <= m) {
                r = m-1;
            }
        }

        if (citations[len-1-l] >= l+1) {
            return l+1;
        }
        return 0;
    }
};
