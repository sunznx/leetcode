class Solution {
public:
    int strStr(string haystack, string needle) {
        int len1 = haystack.size();
        int len2 = needle.size();

        if (len2 > len1 || len2 == len1 && haystack != needle) {
            return -1;
        }

        for (int j = 0; j <= len1-len2; j++) {
            int ok = 1;
            int index = j;
            for (int i = 0; i < len2; i++) {
                if (haystack[index++] != needle[i]) {
                    ok = 0;
                    break;
                }
            }

            if (ok) {
                return j;
            }
        }

        return -1;
    }
};
