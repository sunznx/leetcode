class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int row = matrix.size();
        int col = matrix[0].size();
        const int inf = 0x3fffffff;

        vector<int> used(row);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for (int i = 0; i < row; i++) {
            pq.push({-inf, i});
        }

        int ans = 0;
        for (int t = 0; t < k+row; t++) {
            auto top = pq.top();
            pq.pop();

            ans = top.first;
            auto x = top.second;

            if (used[x] == col) {
                pq.push({inf, x});
            } else {
                auto y = used[x]++;
                auto val = matrix[x][y];
                pq.push({val, x});
            }
        }

        return ans;
    }
};
