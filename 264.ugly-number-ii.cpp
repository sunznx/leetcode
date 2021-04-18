// CreateTime: 2021-04-11 02:18:19
class Solution {
public:
    typedef long long LL;

    int nthUglyNumber(int n) {
        unordered_set<LL> S;
        priority_queue<LL, vector<LL>, greater<LL>> pq;
        pq.push(1);
        S.insert(1);

        int ans = 1;
        while (n--) {
            auto top = pq.top();
            pq.pop();
            ans = top;

            if (S.find(top*2) == S.end()) {
                S.insert(top*2);
                pq.push(top*2);
            }

            if (S.find(top*3) == S.end()) {
                S.insert(top*3);
                pq.push(top*3);
            }

            if (S.find(top*5) == S.end()) {
                S.insert(top*5);
                pq.push(top*5);
            }
        }

        return ans;
    }
};
