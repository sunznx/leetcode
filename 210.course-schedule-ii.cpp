// CreateTime: 2020-01-09 10:34:13
class Solution {
public:

    vector<int> d;
    vector<bool> v;
    vector<vector<int>> g;
    queue<int> q;

    int leaves;
    vector<int> res;

    void add(int x, int y) {
        g[y].push_back(x);
        d[x]++;
    }

    void fintRoot() {
        for (int k = 0; k < d.size(); k++) {
            if (d[k] == 0) {
                q.push(k);
                res.push_back(k);
                v[k] = true;
                leaves--;
            }
        }
    }

    void bfs() {
        bool ok = true;
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
                    res.push_back(k);
                    v[k] = true;
                    leaves--;
                }
            }
        }
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        leaves = numCourses;
        v.resize(numCourses);
        d.resize(numCourses);
        g.resize(numCourses);

        for (int i = 0; i < prerequisites.size(); i++) {
            auto x = prerequisites[i][0];
            auto y = prerequisites[i][1];
            add(x, y);
        }

        fintRoot();
        bfs();

        if (leaves == 0) {
            return res;
        }
        return {};
    }
};
