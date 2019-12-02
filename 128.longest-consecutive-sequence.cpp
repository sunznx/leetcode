// CreateTime: 2019-12-02 00:43:55
class Solution {
public:
    
    int ans;
    unordered_map<int, int> m;
    unordered_map<int, int> p;
    
    void init(int x) {
        if (m.find(x) == m.end()) {
            p[x] = x;
            m[x] = 1;
        } 
    }

    int find(int x) {
        init(x);
        if (x != p[x]) {
            p[x] = find(p[x]);
        }
        return p[x];
    }
    
    void merge(int x, int y) {
        int p1 = find(x);
        int p2 = find(y);
        
        if (p1 != p2) {
            p[p2] = p1;
            m[p1] += m[p2];
        }
    }
    
    int longestConsecutive(vector<int>& nums) {
        ans = 0;

        int len = nums.size();
        for (int i = 0; i < len; i++) {
            int p = find(nums[i]);
            if (m.find(nums[i]-1) != m.end()) {
                merge(p, nums[i]-1);
            }
            if (m.find(nums[i]+1) != m.end()) {
                merge(p, nums[i]+1);
            }
            
            ans = max(ans, m[p]);
        }
        
        return ans;
    }
};
