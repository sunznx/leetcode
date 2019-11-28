// // CreateTime: 2019-11-28 10:55:35
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

// CreateTime: 2019-11-28 10:18:13
class Solution {
public:

    struct Point {
        int x;
        int y;

        int distance(Point &p) {
            return (x-p.x)*(x-p.x) + (y-p.y)*(y-p.y);
        }
    };

    int numberOfBoomerangs(vector<vector<int>>& points) {
        int len = points.size();

        vector<Point> p(len);

        vector<unordered_map<int, unordered_set<int>>> distance(len);

        for (int i = 0; i < len; i++) {
            p[i].x = points[i][0];
            p[i].y = points[i][1];
        }

        for (int i = 0; i < len; i++) {
            for (int j = 0; j < len; j++) {
                int d = p[i].distance(p[j]);
                distance[i][d].insert(j);
            }
        }

        int ans = 0;
        for (int i = 0; i < len; i++) {
            for (auto &item: distance[i]) {
                auto d = item.first;
                auto size = item.second.size();
                ans +=  size * (size-1);
            }
        }

        return ans;
    }
};

// int main(void) {
//     vector<vector<int>> p = {{0,0},{1,0},{2,0}};
//     Solution s;
//     cout << s.numberOfBoomerangs(p) << endl;

//     return 0;
// }
