// // CreateTime: 2021-01-17 19:58:52
// class Solution {
// public:
//     queue<int> que;
//     vector<bool> seen;
//     unordered_map<int, unordered_set<int>> m;
//     int ans = 0;

//     int minJumps(vector<int>& arr) {
//         int len = arr.size();
//         seen.resize(len);

//         for (int i = 0; i < len; i++) {
//             auto x = arr[i];
//             m[x].insert(i);
//         }

//         que.push(0);
//         seen[0] = true;

//         while (!que.empty()) {
//             auto k = que.size();

//             while (k--) {
//                 auto front = que.front();
//                 que.pop();

//                 if (front == len-1) {
//                     return ans;
//                 }

//                 auto k1 = front-1;
//                 auto k2 = front+1;

//                 if (0 <= k1 && k1 <= len-1 && !seen[k1]) {
//                     seen[k1] = true;
//                     que.push(k1);
//                 }
//                 if (0 <= k2 && k2 <= len-1 && !seen[k2]) {
//                     seen[k2] = true;
//                     que.push(k2);
//                 }

//                 auto x = arr[front];
//                 for (auto &e: m[x]) {
//                     if (!seen[e]) {
//                         seen[e] = true;
//                         que.push(e);
//                     }
//                 }
//                 m[x].clear();
//             }
//             ans++;
//         }

//         return -1;
//     }
// };


class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();

        vector<int> dis(n, INT_MAX); // 距离
        vector<int> vis(n, 0); // 访问标记
        unordered_map<int, vector<int>> m; // 倒排加速(m既起到了倒排加速作用，又起到了记录值是否被访问的作用，如果有一个值被访问过了，删除该值对应的键)
        for (int i = 0; i < n-1; i++)
            m[arr[i]].push_back(i);

        dis[n-1] = 0; // 最后一个点入队
        queue<int> q;
        q.push(n-1);

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            if (u-1 >= 0 && !vis[u-1] && m.find(arr[u-1]) != m.end()) { // 左跳（其中m判断了该值是否被访问过）
                dis[u-1] = min(dis[u-1], dis[u]+1);
                vis[u-1] = 1;
                q.push(u-1);
            }
            if (u+1 < n && !vis[u+1] && m.find(arr[u+1]) != m.end()) { // 右跳
                dis[u+1] = min(dis[u+1], dis[u]+1);
                vis[u+1] = 1;
                q.push(u+1);
            }
            if (m.find(arr[u]) != m.end()) {
                for (int v: m[arr[u]]) {
                    if (!vis[v]) {
                        vis[v] = 1;
                        dis[v] = min(dis[u]+1, dis[v]);
                        q.push(v);
                    }
                }
                m.erase(arr[u]); // 访问过的值直接清理掉
            }
        }
        return dis[0];
    }
};