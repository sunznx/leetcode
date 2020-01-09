// CreateTime: 2020-01-06 23:50:29
class Solution {
public:
    vector<vector<bool>> g;
    vector<int> d;
    vector<bool> v;
    queue<int> q;
    bool ok = true;
    int leaves;

    void add(int x, int y) {
        g[x][y] = true;
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

            for (int k = 0; k < d.size(); k++) {
                if (v[k] && g[top][k] == true) {
                    ok = false;
                    break;
                }

                if (v[k] || g[top][k] == false) {
                    continue;
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
        g.resize(numCourses, vector<bool>(numCourses));

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