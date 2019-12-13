// CreateTime: 2019-12-13 09:00:00
class Solution {
public:
    vector<vector<int>> res;
    vector<int> arr;

    vector<vector<int>> combinationSum3(int k, int n) {
        return res;
    }
    
    void dfs(int k, int n, int from = 1, int step = 0) {
        if (step == k) {
            if (n == 0) {
                res.push_back(arr);    
            }
            return;
        }
        
        if (n <= 0) {
            return;
        }
        
        for (int i = from; i <= 9; i++) {
            arr.push_back(i);
            dfs(k, n-i, i+1, step+1);
            arr.pop_back();
        }
    }
};
