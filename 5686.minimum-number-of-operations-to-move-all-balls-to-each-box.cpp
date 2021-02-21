// CreateTime: 2021-02-21 10:34:29
class Solution {
public:
    vector<int> minOperations(string boxes) {
        int len = boxes.size();
        vector<int> ans(len);

        for (int i = 0; i < len; i++) {
            for (int j = 0; j < i; j++) {
                if (boxes[j] == '1') {
                    ans[i] += i-j;
                }
            }
            for (int j = i+1; j < len; j++) {
                if (boxes[j] == '1') {
                    ans[i] += j-i;
                }
            }
        }

        return ans;
    }
};