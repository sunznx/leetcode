// CreateTime: 2021-01-05 00:40:59
class Solution {
public:
    vector<double> sampleStats(vector<int>& count) {
        vector<double> ans;

        double minV = INT_MAX;
        double maxV = INT_MIN;
        double midV = 0;
        double multiV = 0;
        double sum = 0;

        double maxX = 0;
        int sumX = 0;

        for (int i = 0; i < count.size(); i++) {
            auto x = count[i];
            sumX += x;

            if (x > 0) {
                minV = min(minV, double(i));
                maxV = max(maxV, double(i));
                sum += i * x;
            }

            if (x > maxX) {
                maxX = x;
                multiV = i;
            }
        }

        int mid1;
        int mid2;
        if (sumX % 2 == 0) {
            mid1 = sumX/2;
            mid2 = sumX/2+1;
        } else {
            mid1 = sumX/2+1;
            mid2 = sumX/2+1;
        }

        double midv1 = -1;
        double midv2 = -1;

        cout << sumX << endl;
        cout << mid1 << " " << mid2 << endl;

        int newSumX = 0;
        for (int i = 0; i < count.size(); i++) {
            auto x = count[i];
            cout << newSumX << " -- " << newSumX + x << endl;
            if (newSumX < mid1 && newSumX+x >= mid2) {
                midv1 = i;
                midv2 = i;
                cout << midv1 << " " << midv2 << endl;
                break;
            } else if (newSumX < mid1 && newSumX+x >= mid1) {
                midv1 = i;
                cout << midv1 << " " << midv2 << endl;
            } else if (newSumX >= mid1 && newSumX+x >= mid2) {
                midv2 = i;
                cout << midv1 << " " << midv2 << endl;
                break;
            }

            newSumX += x;
        }

        ans.push_back(minV);
        ans.push_back(maxV);
        ans.push_back(sum/sumX);
        ans.push_back((midv1+midv2)/2);
        ans.push_back(multiV);

        return ans;
    }
};
