// CreateTime: 2021-01-05 00:40:59
class Solution {
public:
    vector<double> sampleStats(vector<int>& count) {
        double minVal = INT_MAX;
        double maxVal = INT_MIN;
        double midV = 0;
        double multiV = 0;
        double sum = 0;

        double maxX = 0;
        int cnt = 0;

        for (int i = 0; i < count.size(); i++) {
            auto x = count[i];
            cnt += x;

            if (x > 0) {
                minVal = min(minVal, double(i));
                maxVal = max(maxVal, double(i));
                sum += i * x;
            }

            if (x > maxX) {
                maxX = x;
                multiV = i;
            }
        }

        // 计算中位数
        int mid1;
        int mid2;
        if (cnt % 2 == 0) {
            mid1 = cnt/2;
            mid2 = cnt/2+1;
        } else {
            mid1 = cnt/2+1;
            mid2 = cnt/2+1;
        }

        double midv1 = -1;
        double midv2 = -1;

        int newCnt = 0;
        for (int i = 0; i < count.size(); i++) {
            auto x = count[i];
            if (newCnt < mid1 && newCnt+x >= mid2) {
                midv1 = i;
                midv2 = i;
                break;
            } else if (newCnt < mid1 && newCnt+x >= mid1) {
                midv1 = i;
            } else if (newCnt >= mid1 && newCnt+x >= mid2) {
                midv2 = i;
                break;
            }

            newCnt += x;
        }

        return vector<double>{minVal, maxVal, sum/cnt, (midv1+midv2)/2, multiV};
    }
};
