// CreateTime: 2021-01-17 19:58:52
class Solution {
public:
    queue<int> que;
    vector<bool> seen;
    unordered_map<int, vector<int>> m;
    int ans = 0;

    int minJumps(vector<int>& arr) {
        int len = arr.size();
        seen.resize(len);

        for (int i = 0; i < len; i++) {
            auto x = arr[i];
            m[x].push_back(i);
        }

        que.push(0);
        seen[0] = true;

        while (!que.empty()) {
            auto k = que.size();

            while (k--) {
                auto front = que.front();
                que.pop();

                if (front == len-1) {
                    return ans;
                }

                auto k1 = front-1;
                auto k2 = front+1;

                if (0 <= k1 && k1 <= len-1 && !seen[k1]) {
                    seen[k1] = true;
                    que.push(k1);
                }
                if (0 <= k2 && k2 <= len-1 && !seen[k2]) {
                    seen[k2] = true;
                    que.push(k2);
                }

                auto x = arr[front];
                for (auto &e: m[x]) {
                    if (!seen[e]) {
                        seen[e] = true;
                        que.push(e);
                    }
                }
                m[x].clear();
            }
            ans++;
        }

        return -1;
    }
};