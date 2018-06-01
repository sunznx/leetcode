class Solution {
public:
    vector<int> constructRectangle(int area) {
        vector<int> res(2, 0);
        res[0] = area;
        res[1] = 1;
        for (int i = 2; i * i <= area; i++) {
            int one = area / i;
            int two = i;
            if (area % i == 0 && one - two < res[0] - res[1]) {
                res[0] = one;
                res[1] = two;
            }
        }

        return res;
    }
};
