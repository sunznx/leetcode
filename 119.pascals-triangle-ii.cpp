class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> tmp(rowIndex+1, 0);
        vector<int> v(rowIndex+1, 0);
        for (int i = 1; i <= rowIndex+1; i++) {
            for (int j = 1; j <= i; j++) {
                if (i == 1 || i == j || j == 1) {
                    tmp[j-1] = 1;
                    v[j-1] = 1;
                } else {
                    v[j-1] = tmp[j-2] + tmp[j-1];
                }
            }
            tmp = v;
        }

        return v;
    }
};
