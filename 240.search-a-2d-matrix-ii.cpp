// // CreateTime: 2019-11-30 01:08:36
// #include <iostream>
// #include <cstdio>
// #include <cstdlib>
// #include <cstring>
// #include <string>
// #include <sstream>
// #include <cmath>
// #include <algorithm>
// #include <queue>
// #include <deque>
// #include <vector>
// #include <list>
// #include <stack>
// #include <map>
// #include <set>
// #include <unordered_set>
// #include <unordered_map>

// using namespace std;

// CreateTime: 2019-11-29 11:52:58
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        if (row == 0) {
            return false;
        }

        int col = matrix[0].size();
        if (col == 0) {
            return false;
        }

        int maxl = 0;
        int maxr = col-1;

        for (int j = 0; j < col; j++) {
            int l = maxl;
            int r = maxr;

            while (l < r) {
                int mid = (l+r) / 2;
                if (matrix[0][mid] < target) {
                    l = mid+1;
                } else {
                    r = mid;
                    maxr = min(maxr, mid);
                }
            }
        }

        for (int j = 0; j < col; j++) {
            int l = maxl;
            int r = maxr;

            while (l < r) {
                int mid = (l+r) / 2;
                if (matrix[row-1][mid] < target) {
                    l = mid+1;
                    maxl = max(maxl, mid);
                } else {
                    r = mid;
                }
            }
        }

        for (int i = 0; i < row; i++) {
            int l = maxl;
            int r = maxr;

            while (l < r) {
                int mid = (l+r) / 2;
                if (matrix[i][mid] < target) {
                    l = mid+1;
                } else {
                    r = mid;
                }
            }

            if (matrix[i][l] == target) {
                return true;
            }
        }

        return false;
    }
};

// int main(void) {
//     // vector<vector<int>> matrix = {
//     //     {1,4,7,11,15},
//     //     {2,5,8,12,19},
//     //     {3,6,9,16,22},
//     //     {10,13,14,17,24},
//     //     {18,21,23,26,30}
//     // };
//     // int target = 13;

//     vector<vector<int>> matrix = {
//         {1,3,5,7,9},
//         {2,4,6,8,10},
//         {11,13,15,17,19},
//         {12,14,16,18,20},
//         {21,22,23,24,25}
//     };
//     int target = 24;

//     Solution s;
//     cout << s.searchMatrix(matrix, target) << endl;

//     return 0;
// }
