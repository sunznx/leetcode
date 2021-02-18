// // CreateTime: 2021-02-18 14:50:43
// class Solution {
// public:
//     unordered_map<int, unordered_set<int>> m;

//     int minTrioDegree(int n, vector<vector<int>>& edges) {
//         for (auto &edge: edges) {
//             auto x = edge[0];
//             auto y = edge[1];

//             m[x].insert(y);
//             m[y].insert(x);
//         }

//         int ans = INT_MAX;

//         for (int i = 1; i <= n; i++) {
//             if (m.find(i) == m.end()) {
//                 continue;
//             }

//             for (int j = i+1; j <= n; j++) {
//                 if (m.find(j) == m.end() || m[i].find(j) == m[i].end()) {
//                     continue;
//                 }

//                 for (int k = j+1; k <= n; k++) {
//                     if (m.find(k) == m.end() || m[i].find(k) == m[i].end() || m[j].find(k) == m[j].end()) {
//                         continue;
//                     }

//                     int x = m[i].size()-2 + m[j].size()-2 + m[k].size()-2;
//                     ans = min(ans, x);
//                 }
//             }
//         }

//         if (ans == INT_MAX) {
//             return -1;
//         }

//         return ans;
//     }
// };

class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        int ans = INT_MAX;
        vector<int> inDegrees(n);
        vector<vector<bool>> isConnected(n, vector<bool>(n));
        for (auto &edge : edges) {
            isConnected[edge[0] - 1][edge[1] - 1] = isConnected[edge[1] - 1][edge[0] - 1] = true;
            inDegrees[edge[0] - 1]++;
            inDegrees[edge[1] - 1]++;
        }
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j) {
                if (!isConnected[i][j])
                    continue;
                for (int k = j + 1; k < n; ++k) {
                    if (isConnected[i][k] && isConnected[j][k])
                        ans = min(ans, inDegrees[i] + inDegrees[j] + inDegrees[k] - 6);
                }
            }
        return ans == INT_MAX ? -1 : ans;
    }
};