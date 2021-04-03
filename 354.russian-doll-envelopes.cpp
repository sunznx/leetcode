// CreateTime: 2021-04-03 21:46:45
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [](vector<int> &e1, vector<int> &e2) {
            return (e1[0] < e2[0]) || (e1[0] == e2[0] && e1[1] > e2[1]);
        });

        vector<int> arr;

        for (int i = 0; i < envelopes.size(); i++) {
            auto x = envelopes[i][1];

            int l = 0;
            int r = arr.size()-1;

            while (l < r) {
                int m = (l+r) / 2;

                if (x <= arr[m]) {
                    r = m;
                } else if (x > arr[m]) {
                    l = m+1;
                }
            }

            if (l >= arr.size() || x > arr[arr.size()-1]) {
                arr.push_back(x);
            } else {
                arr[l] = x;
            }
        }

        return arr.size();
    }
};
