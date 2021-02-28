// CreateTime: 2021-02-28 11:25:55
class Solution {
public:
    typedef tuple<double, int, int> DII;

    int len;
    vector<double> ans;
    priority_queue<DII, vector<DII>, greater<DII>> pq;
    vector<int> next;
    vector<int> prev;

    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        len = cars.size();
        ans.resize(len, -1);
        next.resize(len);
        prev.resize(len, -1);

        for (int i = 0; i < len-1; i++) {
            auto pos = cars[i][0];
            auto speed = cars[i][1];

            auto nextPos = cars[i+1][0];
            auto nextSpeed = cars[i+1][1];

            next[i] = i+1;
            prev[i+1] = i;

            double needTime = INT_MAX;
            if (speed > nextSpeed) {
                needTime = (double)(nextPos-pos) / (double)(speed-nextSpeed);
            }

            pq.push({needTime, i, i+1});
        }

        while (pq.size()) {
            auto [needTime, k, nextK] = pq.top();
            pq.pop();

            if (nextK != next[k]) {
                continue;
            }

            if (abs(needTime - INT_MAX) < 1e-5) {
                ans[k] = -1;
            } else {
                ans[k] = needTime;
            }

            auto pos = cars[k][0];
            auto speed = cars[k][1];
            auto nextPos = cars[nextK][0];
            auto nextSpeed = cars[nextK][1];
            prev[nextK] = prev[k];

            if (prev[nextK] >= 0) {
                auto pos = cars[prev[nextK]][0];
                auto speed = cars[prev[nextK]][1];

                auto nextPos = cars[nextK][0];
                auto nextSpeed = cars[nextK][1];

                next[prev[nextK]] = nextK;

                double needTime = INT_MAX;
                if (speed > nextSpeed) {
                    needTime = (double)(nextPos-pos) / (double)(speed-nextSpeed);
                }
                pq.push({needTime, prev[nextK], nextK});
            }
        }

        return ans;
    }
};