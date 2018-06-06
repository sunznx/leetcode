class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        vector<int> res;

        vector<int> v(nums.size(), -1);
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i+1; j < nums.size(); j++) {
                if (nums[j] > nums[i]) {
                    v[i] = nums[j];
                    break;
                }
            }
        }
        

        for (int i = 0; i < findNums.size(); i++) {
            bool found = false;
            for (int j = 0; j < nums.size(); j++) {
                if (nums[j] == findNums[i]) {
                    found = true;
                    res.push_back(v[j]);
                    break;
                }
            }
            if (!found) {
                res.push_back(-1);
            }
        }

        return res;
    }
};
