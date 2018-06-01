class Solution {
public:
    int calPoints(vector<string>& ops) {
        int res = 0;
        int len = ops.size();
        
        vector<int> arr(len, 0);
        for (int i = 0; i < len; i++) {
            if (ops[i] == "D") {
                arr[i] = arr[i-1] * 2;
                res += arr[i];
            } else if (ops[i] == "C") {
                res -= arr[i-1];
                for (int j = i; j > 0; j--) {
                    arr[j] = arr[j-2];
                }
                arr[0] = 0;
                arr[1] = 0;
            } else if (ops[i] == "+") {
                arr[i] = arr[i-1] + arr[i-2];
                res += arr[i];
            } else {
                arr[i] = atoi(ops[i].c_str());
                res += arr[i];
            }
        }

        return res;
    }
};
