// CreateTime: 2020-01-07 16:40:50
class Solution {
public:
    vector<int> parent;

    void init() {
        for (int i = 0; i < parent.size(); i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (x != parent[x]) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        init();
        
        int len = edges.size();
        for (int i = 0; i < len; i++) {
            auto x = edges[i][0];
            auto y = edges[i][1];
            
            auto px = find(x);
            auto py = find(y);
            
            if (px == py) {
                return false;
            }
            
            parent[py] = px;
            n--;
        }

        return n == 1;
    }
};
