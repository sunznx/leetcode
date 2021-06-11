// CreateTime: 2021-06-11 18:19:42
class Solution {
public:
    vector<vector<int>> g;
    vector<int> seen;
    vector<int> ans;

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        g.resize(numCourses);
        seen.resize(numCourses);

        for (auto &x: prerequisites) {
            g[x[0]].push_back(x[1]);
        }

        for (int i = 0; i < numCourses; i++) {
            if (seen[i] == 0) {
                if (dfs(i) == false) {
                    return {};
                }
            }
        }
        return ans;
    }

    bool dfs(int x) {
        seen[x] = 1;
        for (auto &y: g[x]) {
            if (seen[y] == 0) {
                if (dfs(y) == false) {
                    return false;
                }
            } else if (seen[y] == 1) {
                return false;
            }
        }

        seen[x] = 2;
        ans.push_back(x);
        return true;
    }
};
