// CreateTime: 2021-01-10 11:56:06
class Solution {
public:
    vector<int> parent;

    void init() {
        for (int i = 0; i < parent.size(); i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void uf(int x, int y) {
        int px = find(x);
        int py = find(y);
        parent[px] = py;
    }

    bool connected(int x, int y) {
        return find(x) == find(y);
    }

    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int len = source.size();

        parent.resize(len);
        init();

        for (int i = 0; i < allowedSwaps.size(); i++) {
            auto x = allowedSwaps[i][0];
            auto y = allowedSwaps[i][1];
            uf(x, y);
        }

        vector<bool> visted(len);

        unordered_map<int, unordered_set<int>> m;
        for (int i = 0; i < len; i++) {
            auto x = target[i];
            m[x].insert(i);
        }

        int ans = 0;
        for (int i = 0; i < len; i++) {
            auto x = source[i];
            int found = -1;

            if (!visted[i] && x == target[i]) {
                found = i;
            } else {
                for (auto k: m[x]) {
                    if (!visted[k] && connected(i, k)) {
                        found = k;
                        break;
                    }
                }
            }

            if (found == -1) {
                ans++;
            } else {
                visted[found] = true;
            }
        }

        return ans;
    }
};