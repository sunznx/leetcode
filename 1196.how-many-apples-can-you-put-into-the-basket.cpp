// CreateTime: 2019-12-21 01:03:33
class Solution {
public:
    int maxNumberOfApples(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        
        int ans = 0;
        int leaves = 5000;

        int len = arr.size();
        for (int i = 0; i < len; i++) {
            if (leaves < arr[i]) {
                break;
            }
            
            leaves -= arr[i];
            ans += 1;
        }
        
        return ans;
    }
};
