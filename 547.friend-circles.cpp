// CreateTime: 2019-12-23 18:04:29
class Solution {
public:
    
    vector<int> parent;

    int res;

    int find(int x) {
        if (x != parent[x]) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void merge(int x, int y) {
        int px = find(x);
        int py = find(y);

        if (px == py) {
            return;
        }
        
        res -= 1;
        parent[py] = px;
    }

    int findCircleNum(vector<vector<int>>& M) {
        int len = M.size();

        res = len;
        parent.resize(len);

        for (int i = 0; i < len; i++) {
            parent[i] = i;
        }
        
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < len; j++) {
                if (M[i][j] == 1) {
                    merge(i, j);
                }
            }
        }
        
        return res;
    }
};
