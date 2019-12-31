// CreateTime: 2019-12-31 12:35:40
class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        vector<int> res(queries.size());

        int len = A.size();

        int sum = 0;
        for (int i = 0; i < len; i++) {
            if (A[i] % 2 == 0) {
                sum += A[i];
            }
        }

        for (int i = 0; i < queries.size(); i++) {
            auto diff = queries[i][0];
            auto index = queries[i][1];

            auto v = A[index];
            auto newV = A[index] + diff;

            if (v % 2 == 0 && newV % 2 == 0) {
                sum += diff;
            } else if (v % 2 == 0 && newV % 2 != 0) {
                sum -= v;
            } else if (v % 2 != 0 && newV % 2 == 0) {
                sum += newV;
            } else if (v % 2 != 0 && newV % 2 != 0) {
                //
            }

            res[i] = sum;
            A[index] = newV;
        }

        return res;
    }
};
