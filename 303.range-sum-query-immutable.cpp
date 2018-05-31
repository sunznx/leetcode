class NumArray {
public:
    vector<int> sum;

    NumArray(vector<int> nums) {
        int len = nums.size();

        int total = 0;
        for (int i = 0; i < len; i++) {
            total += nums[i];
            sum.push_back(total);
        }
    }

    int sumRange(int i, int j) {
        if (i == 0) {
            return sum[j];
        }

        return sum[j] - sum[i-1];
    }
};
