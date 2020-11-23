// CreateTime: 2020-11-23 16:44:39
class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int ans = 0;

        vector<pair<int, int>> arr;
        for (int k = 0; k < difficulty.size(); k++) {
            arr.push_back({difficulty[k], profit[k]});
        }

        sort(worker.begin(), worker.end());
        sort(arr.begin(), arr.end());

        int r = 0;
        int sub = 0;

        for (int k = 0; k < worker.size(); k++) {
            auto x = worker[k];

            while (r < arr.size() && x >= arr[r].first) {
                sub = max(sub, arr[r++].second);
            }

            ans += sub;

            cout << sub << endl;
        }

        return ans;
    }
};
