// CreateTime: 2021-02-18 17:37:13
class Solution {
public:
    int maximumScore(int a, int b, int c) {
        int ans = 0;
        priority_queue<int, vector<int>, less<int>> pq;

        pq.push(a);
        pq.push(b);
        pq.push(c);

        while (true) {
            auto t1 = pq.top();
            pq.pop();

            auto t2 = pq.top();
            pq.pop();

            auto t3 = pq.top();
            pq.pop();

            if (t2 == 0) {
                break;
            }

            int k = max(t2-t3, 1);
            ans += k;

            pq.push(t1-k);
            pq.push(t2-k);
            pq.push(t3);
        }

        return ans;
    }
};
