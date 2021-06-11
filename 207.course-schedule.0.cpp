// CreateTime: 2021-06-11 17:18:49
class Solution {
public:
    vector<vector<int>> g;
    vector<int> seen;

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        g.resize(numCourses);
        seen.resize(numCourses);

        for (auto &x: prerequisites) {
            g[x[0]].push_back(x[1]);
        }

        for (int i = 0; i < numCourses; i++) {
            if (seen[i] == 0) {
                if (dfs(i) == false) {
                    return false;
                }
            }
        }
        return true;
    }

    bool dfs(int x = 0) {
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
        return true;
    }
};
