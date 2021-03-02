// CreateTime: 2021-02-26 13:00:40
class Solution {
public:
    int len;
    vector<int> nums;

    Solution(vector<int>& nums) {
        this->nums = nums;
        len = nums.size();
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return nums;
    }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> ans(nums.begin(), nums.end());

        for (int i = 0; i < len; i++) {
            int pos = rand() % (len-i);
            swap(ans[pos], ans[len-1-i]);
        }

        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
