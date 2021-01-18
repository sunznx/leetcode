// CreateTime: 2021-01-19 00:19:27
class NumArray {
public:
    vector<int> p;

    NumArray(vector<int> nums) {
        p.resize(nums.size()+1);

        for (int i = 0; i < nums.size(); i++) {
            p[i+1] = p[i] + nums[i];
        }
    }

    int sumRange(int i, int j) {
        return p[j+1] - p[i];
    }
};
