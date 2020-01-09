// CreateTime: 2020-01-06 23:50:29
class Solution {
public:
    vector<int> d;
    vector<bool> v;
    queue<int> q;
    vector<vector<int>> g;

    bool ok = true;
    int leaves;

    void add(int x, int y) {
        g[x].push_back(y);
        d[y] += 1;
    }

    void findRoot() {
        for (int k = 0; k < d.size(); k++) {
            if (d[k] == 0) {
                q.push(k);
                v[k] = true;
                leaves--;
            }
        }
    }

    void bfs() {
        while (q.size() && ok) {
            auto top = q.front();
            q.pop();

            for (auto &k: g[top]) {
                if (v[k]) {
                    ok = false;
                    break;
                }

                d[k]--;
                if (d[k] == 0) {
                    q.push(k);
                    v[k] = true;
                    leaves--;
                }
            }
        }
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        leaves = numCourses;
        v.resize(numCourses);
        d.resize(numCourses);
        g.resize(numCourses);

        for (int i = 0; i < prerequisites.size(); i++) {
            auto x = prerequisites[i][0];
            auto y = prerequisites[i][1];
            add(x, y);
        }

        findRoot();

        bfs();

        return leaves == 0;
    }
};