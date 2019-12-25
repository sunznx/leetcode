// CreateTime: 2019-12-25 22:49:39
class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int len = seats.size();

        int k = 0;
        int ans = 1;
        bool isFirst = true;
        for (int i = 0; i < len; i++) {
            if (seats[i] == 0) {
                k++;
                if (i == len-1) {
                    ans = max(ans, k);
                }
            }

            if (seats[i] != 0) {
                if (seats[0] == 0 && isFirst) {
                    isFirst = false;
                    ans = max(ans, k);
                } else {
                    ans = max(ans, (k-1)/2+1);
                }
                k = 0;
            }


        }

        return ans;
    }
};
