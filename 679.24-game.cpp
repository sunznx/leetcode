// CreateTime: 2021-03-11 17:40:14
class Solution {
public:

    const double EXP = 1e-4;

    const int OP_ADD = 0;
    const int OP_SUB = 1;
    const int OP_MUL = 2;
    const int OP_DIV = 3;

    bool ans = false;

    bool judgePoint24(vector<int>& nums) {
        vector<double> arr(nums.begin(), nums.end());
        return judgePoint24(arr);
    }

    bool judgePoint24(vector<double>& nums) {
        if (nums.size() == 1) {
            if (check(nums[0])) {
                return true;
            }
            return false;
        }

        vector<bool> seen(nums.size());
        vector<double> arr(nums.size());
        return dfs(nums, seen, arr);
    }

    bool dfs(vector<double>& nums, vector<bool> &seen, vector<double> &arr, int s = 0) {
        if (s == nums.size()) {
            auto n1 = arr[0];
            arr.erase(arr.begin());
            auto n2 = arr[0];
            arr.erase(arr.begin());

            for (int op = 0; op < 4; op++) {
                arr.insert(arr.begin(), calc(op, n1, n2));
                if (judgePoint24(arr)) {
                    return true;
                }
                arr.erase(arr.begin());
            }

            arr.insert(arr.begin(), n2);
            arr.insert(arr.begin(), n1);
            return false;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (!seen[i]) {
                seen[i] = true;
                arr[s] = nums[i];
                if (dfs(nums, seen, arr, s+1)) {
                    return true;
                }
                seen[i] = false;
            }
        }
        return false;
    }

    bool check(double x) {
        if (fabs(x - 24) <= EXP) {
            return true;
        }
        return false;
    }

    double calc(int op, double x, double y) {
        if (op == OP_ADD) {
            return x + y;
        }

        if (op == OP_SUB) {
            return x - y;
        }

        if (op == OP_MUL) {
            return x * y;
        }

        if (op == OP_DIV) {
            return x / y;
        }

        return -1;
    }
};