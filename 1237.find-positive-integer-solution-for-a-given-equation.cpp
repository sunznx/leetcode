/*
 * // This is the custom function interface.
 * // You should not implement it, or speculate about its implementation
 * class CustomFunction {
 * public:
 *     // Returns f(x, y) for any given positive integers x and y.
 *     // Note that f(x, y) is increasing with respect to both x and y.
 *     // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
 *     int f(int x, int y);
 * };
 */

class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
        vector<vector<int>> res;

        bool ok = true;
        for (int i = 1; i <= 1000 && ok; i++) {
            for (int j = 1; j <= 1000; j++) {
                int Z = customfunction.f(i, j);
                if (Z == z) {
                    vector<int> v;
                    v.push_back(i);
                    v.push_back(j);
                    res.push_back(v);
                }
                if (Z > z) {
                    if (j == 1) {
                        ok = false;
                    } else {
                        break;
                    }
                }
            }
        }

        return res;
    }
};
