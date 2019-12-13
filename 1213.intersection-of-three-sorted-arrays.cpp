// CreateTime: 2019-12-13 18:50:12
class Solution {
public:
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
        int len1 = arr1.size();
        int len2 = arr2.size();
        int len3 = arr3.size();
        
        int k1 = 0;
        int k2 = 0;
        int k3 = 0;

        vector<int> res;
        while (k1 < len1 && k2 < len2 && k3 < len3) {
            int x1 = arr1[k1];
            int x2 = arr2[k2];
            int x3 = arr3[k3];

            if (x1 == x2 && x2 == x3) {
                k1++;
                k2++;
                k3++;
                res.push_back(x1);
                continue;
            }
            
            if (x1 <= x2 && x1 <= x3) {
                k1++;
            } else if (x2 <= x1 && x2 <= x3) {
                k2++;
            } else if (x3 <= x1 && x3 <= x2) {
                k3++;
            }
        }
        return res;
    }
};
