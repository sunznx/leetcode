class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        
        int len = nums.size();
        
        vector<bool> v(len+1, false);
        
        for (int i = 0; i < len; i++) {
            v[nums[i]] = true;
        }
        
        for (int i = 1; i <= len; i++) {
            if (v[i] == false) {
                res.push_back(i);
            }
        }
        
        return res;
    }
};
