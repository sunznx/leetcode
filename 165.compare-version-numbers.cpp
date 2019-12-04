// CreateTime: 2019-12-04 11:23:17
class Solution {
public:
    int compareVersion(string version1, string version2) {
        int len1 = version1.size();
        int len2 = version2.size();
        
        int s1 = 0;
        int s2 = 0;

        while (s1 < len1 || s2 < len2) {
            long long res1 = 0;
            long long res2 = 0;
            
            while (s1 < len1) {
                char c = version1[s1++];
                if (c == '.') {
                    break;
                }                
                res1 = res1 * 10 + c - '0';
            }
            
            while (s2 < len2) {
                char c = version2[s2++];
                if (c == '.') {
                    break;
                }
                res2 = res2 * 10 + c - '0';
            }
            
            if (res1 > res2) {
                return 1;
            } else if (res1 < res2) {
                return -1;
            }
        }

        return 0;
    }
};
