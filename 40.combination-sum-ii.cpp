// CreateTime: 2019-12-13 08:46:32
class Solution {
public:
    vector<vector<int>> res;
    vector<int> arr;
    vector<bool> v;

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        v.resize(candidates.size());
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
            if (i > 0 && candidates[i] == candidates[i-1] && !v[i-1]) {
                continue;
            }
            arr.push_back(candidates[i]);
            v[i] = true;
            dfs(candidates, target-candidates[i], i+1);
            v[i] = false;
            arr.pop_back();
        }
    }
};
