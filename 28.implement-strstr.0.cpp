// CreateTime: 2021-04-20 00:46:30
class Solution {
public:
    int strStr(string haystack, string needle) {
        int len1 = haystack.size();
        int len2 = needle.size();
        for (int i = 0; i <= len1-len2; i++) {
            int k = 0;
            while (k < len2 && haystack[i+k] == needle[k]) {
                k++;
            }
            if (k == len2) {
                return i;
            }
        }
        return -1;
    }
};
