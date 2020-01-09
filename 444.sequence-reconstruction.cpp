// CreateTime: 2020-01-09 10:59:08
class Solution {
public:
    vector<unordered_set<int>> g;
    vector<int> d;
    vector<bool> v;
    int q;
    int qs = 0;

    void add(int x, int y) {
        if (g[x].find(y) != g[x].end()) {
            return;
        }

        g[x].insert(y);
        d[y] += 1;
    }

    void findRoot() {
        for (int k = 1; k < d.size(); k++) {
            if (d[k] == 0) {
                q = k;
                qs++;
                v[k] = true;
            }
        }
    }

    bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
        int len = org.size();
        d.resize(len+1, -1);
        v.resize(len+1);
        g.resize(len+1);

        for (int i = 0; i < seqs.size(); i++) {
            for (int x: seqs[i]) {
                if (x >= d.size()) {
                    return false;
                }
                d[x] = 0;
            }
        }

        for (int i = 0; i < len; i++) {
            if (d[org[i]] == -1) {
                return false;
            }
        }

        for (int i = 0; i < seqs.size(); i++) {
            for (int k = 1; k < seqs[i].size(); k++) {
                auto x = seqs[i][k-1];
                auto y = seqs[i][k];
                add(x, y);
            }
        }

        findRoot();

        bool ok = true;
        for (int i = 0; i < len; i++) {
            if (qs != 1 || q != org[i]) {
                ok = false;
                break;
            }

            qs--;

            for (auto &k: g[org[i]]) {
                if (v[k]) {
                    continue;
                }

                d[k]--;
                if (d[k] == 0) {
                    q = k;
                    qs++;
                }
            }
        }

        return ok;

    }
};
