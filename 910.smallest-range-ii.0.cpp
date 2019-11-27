// CreateTime: 2019-11-27 12:48:44
class Solution {
public:
    int smallestRangeII(vector<int>& A, int K) {
        int len = A.size();

        vector<pair<int, int>> a;
        vector<int> v(len);
        vector<int> pushed(len);

        for (int i = 0; i < len; i++) {
            a.push_back({A[i]-K, i});
            a.push_back({A[i]+K, i});
        }

        sort(a.begin(), a.end());


        for (auto item: a) {
            cout << item.first << " " << item.second << endl;
        }
        cout << endl;


        int res = a[2*len-1].first - a[0].first;

        deque<pair<int, int>> q;
        int cnt = 0;
        for (int i = 0; i < 2*len; i++) {
            auto item = a[i];
            auto first = a[i].first;
            auto second = a[i].second;

            v[second] += 1;
            if (v[second] == 1) {
                cnt += 1;
            }
            q.push_back(a[i]);

            if (cnt == len) {

                if (q.back().second == q.front().second) {
                    q.pop_front();
                }

                res = min(res, q.back().first - q.front().first);
            }

            // 还没满
            while (cnt != len && q.size() && v[q.front().second] == 2) {
                v[q.front().second] -= 1;
                q.pop_front();
            }
        }

        return res;
    }
};