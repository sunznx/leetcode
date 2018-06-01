class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num <= 1) {
            return false;
        }

        vector<int> arr;
        arr.push_back(1);
        for (int i = 2; i*i <= num; i++) {
            if (num % i == 0) {
                int a = i;
                int b = num / i;
                if (a == b) {
                    arr.push_back(a);
                } else {
                    arr.push_back(a);
                    arr.push_back(b);
                }
            }
        }

        int len = arr.size();
        int res = 0;
        for (int i = 0; i < len; i++) {
            res += arr[i];
        }

        return res == num;
    }
};
