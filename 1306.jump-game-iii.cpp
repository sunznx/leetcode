// CreateTime: 2021-01-17 19:47:47
class Solution {
public:
    queue<int> que;
    vector<bool> seen;
    bool canReach(vector<int>& arr, int start) {
        int len = arr.size();
        seen.resize(len);
        que.push(start);
        seen[start] = true;

        while (que.size()) {
            auto k = que.front();
            que.pop();

            if (arr[k] == 0) {
                return true;
            }

            auto k1 = k-arr[k];
            auto k2 = k+arr[k];
            if (k1 >= 0 && !seen[k1]) {
                que.push(k1);
                seen[k1] = true;
            }

            if (k2 < len && !seen[k2]) {
                que.push(k2);
                seen[k2] = true;
            }

        }

        return false;
    }
};
