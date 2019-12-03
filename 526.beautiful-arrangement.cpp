class Solution {
public:
    int res;

    int countArrangement(int N) {
        res = 0;
        vector<int> arr(N+1, 0);
        vector<int> v(N+1, 0);
        dfs(arr, v, N, 0);
        return res;
    }
    
    void dfs(vector<int> &arr, vector<int> &v, int n, int step) {
        if (n == step) {
            res += 1;
            return;
        }
        
        for (int i = 1; i <= n; i++) {
            if (!v[i]) {
                v[i] = 1;
                arr[step+1] = i;
                if (check(arr, step)) {
                    dfs(arr, v, n, step+1);                    
                }
                v[i] = 0;
            }
        }
    }
    
    bool check(vector<int> &arr, int step) {
        bool res = true;
        
        for (int i = 1; i <= step+1; i++) {
            if (arr[i] % i != 0 && i % arr[i] != 0) {
                res = false;
                break;
            }
        }
        
        return res;
    }
};
