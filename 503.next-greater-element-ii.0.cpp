// CreateTime: 2020-11-22 01:43:28
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int len = nums.size();
        for (int i = 0; i < len; i++) {
            nums.push_back(nums[i]);
        }
        
        stack<pair<int, int>> s;
        vector<int> aux(nums.size());
        
        for (int i = len*2-1; i >= 0; i--) {
            auto num = nums[i];
            
            while (s.size() && (s.top().first - i >= len || num >= s.top().second)) {
                s.pop();
            }
            
            if (s.size() == 0) {
                aux[i] = -1;
            } else {
                aux[i] = s.top().second;
            }

            s.push({i, num});
        }
        
        vector<int> res;
        for (int i = 0; i < len; i++) {
            res.push_back(aux[i]);
        }
        
        return res;
    }
};
