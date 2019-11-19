class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        
        if (k > len) {
            k = k % len;
        }

        k = len-k;

        reverse(nums.begin(), nums.begin()+k);
        reverse(nums.begin()+k, nums.end());
        reverse(nums.begin(), nums.end());
    }
};
