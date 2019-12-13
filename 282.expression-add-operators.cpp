// CreateTime: 2019-12-13 14:30:54
class Solution {
public:
    vector<string> res;

    vector<string> addOperators(string num, int target) {
        if (num.size() == 0) {
            return res;
        }

        auto nums = generateNums(num, target);

        for (auto &v: nums) {
            check(v, target);
        }
        return res;
    }

    vector<vector<long long>> generateNums(string &num, int target) {
        vector<vector<long long>> res;
        generateNumsHelper(res, num, target);
        return res;
    }

    void generateNumsHelper(vector<vector<long long>> &res, string &num, long long target, int step = 0, vector<long long> v = {}) {
        int len = num.size();
        if (step == len) {
            res.push_back(v);
            return;
        }

        vector<long long> newV;
        if (v.size() > 0 && v[v.size()-1] != 0) {
            newV = v;
            newV[newV.size()-1] = newV[newV.size()-1] * 10 + (num[step]-'0');
            generateNumsHelper(res, num, target, step+1, newV);
        }

        if (step > 0 && step+1 != len) {
            long long num1 = stoi(num.substr(0, step+1));
            long long num2 = stoi(num.substr(step+1));
            if (abs(num1 * num2) < abs(target) && abs(num1 + num2) < abs(target) && abs(num1 - num2) < abs(target)) {
                return;
            }
        }

        newV = v;
        newV.push_back(num[step]-'0');
        generateNumsHelper(res, num, target, step+1, newV);
    }

    void check(vector<long long> &nums, int target) {
        int len = nums.size();
        auto opArr = generateOp(len-1);
        for (auto &ops: opArr) {
            long long tot = 0;
            auto t = nums;

            for (int i = len-1; i >= 0; i--) {
                auto op = ops[i];
                if (op == '+') {
                    long long num = t[t.size()-1];
                    t.pop_back();
                    tot += num;
                } else if (op == '-') {
                    long long num = t[t.size()-1];
                    t.pop_back();
                    tot -= num;
                } else if (op == '*') {
                    long long num1 = t[t.size()-1];
                    t.pop_back();

                    long long num2 = t[t.size()-1];
                    t.pop_back();

                    t.push_back(num1 * num2);
                }
            }

            if (tot == target) {
                string v = "";
                v += to_string(nums[0]);
                for (int i = 1; i < len; i++) {
                    v += string(1, ops[i]) + to_string(nums[i]);
                }
                res.push_back(v);
            }
        }
    }

    vector<vector<char>> generateOp(int len) {
        vector<vector<char>> res;
        vector<char> ops;
        ops.push_back('+');
        generateOpHelper(res, len, ops);
        return res;
    }

    void generateOpHelper(vector<vector<char>> &res, int len, vector<char> ops, int step = 0) {
        if (step == len) {
            res.push_back(ops);
            return;
        }

        ops.push_back('*');
        generateOpHelper(res, len, ops, step+1);
        ops.pop_back();

        ops.push_back('+');
        generateOpHelper(res, len, ops, step+1);
        ops.pop_back();

        ops.push_back('-');
        generateOpHelper(res, len, ops, step+1);
        ops.pop_back();
    }
};
