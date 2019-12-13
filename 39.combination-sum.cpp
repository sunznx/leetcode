// CreateTime: 2019-12-13 08:39:53
class Solution {
public:
    vector<vector<int>> res;
    vector<int> arr;

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target);
        return res;
    }
    
    void dfs(vector<int>& candidates, int target, int step = 0) {
        if (target < 0) {
            return;
        }
        
        if (target == 0) {
            res.push_back(arr);
            return;
        }
        
        int len = candidates.size();
        for (int i = step; i < len; i++) {
            arr.push_back(candidates[i]);
            dfs(candidates, target-candidates[i], i);
            arr.pop_back();
        }
    }
};
