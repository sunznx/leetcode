// CreateTime: 2019-11-21 22:49:31
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int len = heights.size();

        vector<int> l(len);   // 左边比他大的数有多少个
        vector<int> r(len);   // 右边比他大的数有多少个

        for (int i = 0; i < len; i++) {
            int k = 0;
            for (int j = i-1; j >= 0; j--) {
                if (heights[j] == heights[i]) {
                    k += l[j] + 1;
                    break;
                } else if (heights[j] > heights[i]) {
                    k++;
                } else {
                    break;
                }
            }
            l[i] = k;
        }

        for (int i = len-1; i >= 0; i--) {
            int k = 0;
            for (int j = i+1; j < len; j++) {
                if (heights[j] == heights[i]) {
                    k += r[j] + 1;
                    break;
                } else if (heights[j] > heights[i]) {
                    k++;
                } else {
                    break;
                }
            }
            r[i] = k;
        }

        int res = 0;
        for (int i = 0; i < len; i++) {
            res = max(res, (l[i]+1+r[i]) * heights[i]);
        }

        return res;
    }
};