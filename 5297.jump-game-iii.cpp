// CreateTime: 2019-12-30 10:00:06
class Solution {
public:
    bool ok = false;
    vector<bool> v;
    
    bool canReach(vector<int>& arr, int start) {
        v.resize(arr.size());
        return dfs(arr, start);
    }
    
    bool dfs(vector<int> &arr, int start) {
        if (ok) {
            return true;
        }

        if (! (0 <= start && start <= arr.size()-1)) {
            return false;
        }

        if (v[start] == true) {
            return false;
        }
        
        v[start] = true;
        if (arr[start] == 0) {
            return true;
        }
        
        auto v1 = dfs(arr, start+arr[start]);
        auto v2 = dfs(arr, start-arr[start]);

        if (v1 || v2) {
            ok = true;
            return ok;
        }

        return false;
    }
};
