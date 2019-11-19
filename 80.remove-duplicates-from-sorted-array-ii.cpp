class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        int removed = 0;
        int samed = 1;
        
        for (int i = 1; i < len; i++) {
            if (nums[i] == nums[i-1]) {
                samed += 1;
            }
            
            if (nums[i] != nums[i-1] || i == len-1) {
                int willRemove = samed-2;
                samed = 1;

                if (willRemove > 0) {
                    reverse(nums.begin()+removed, nums.begin()+i);
                    removed += willRemove;
                    reverse(nums.begin()+removed, nums.begin()+i);
                }
            }
        }

        nums.erase(nums.begin(), nums.begin() + removed);
        return nums.size();
    }
};