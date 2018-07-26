class Solution {
public:
    vector<string> res;

    vector<string> readBinaryWatch(int num) {
        vector<bool> bits;
        for (int i = 0; i < 10; i++) {
            bits.push_back(false);
        }
        dfs(bits, num, 0, 0);
        return res;
    }

    void dfs(vector<bool> &bits, int n, int step, int index) {
        if (step == n) {
            int nums1 = 0;
            int nums2 = 0;
            for (int i = 3; i >= 0; i--) {
                int val = 0;
                if (bits[i]) {
                    val = 1;
                }
                nums1 = nums1 * 2 + val;
            }
            for (int i = 9; i >= 4; i--) {
                int val = 0;
                if (bits[i]) {
                    val = 1;
                }
                nums2 = nums2 * 2 + val;
            }
            if (nums1 <= 11 && nums2 <= 59) {
                if (nums2 < 10) {
                    res.push_back(to_string(nums1) + ":0" + to_string(nums2));
                } else {
                    res.push_back(to_string(nums1) + ":" + to_string(nums2));
                }
            }
            return;
        }

        for (int i = index; i < 10; i++) {
            bits[i] = true;
            dfs(bits, n, step+1, i+1);
            bits[i] = false;
        }
    }
};
