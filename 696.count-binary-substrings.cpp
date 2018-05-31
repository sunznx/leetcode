class Solution {
public:
    int findDiff(string s, int from) {
        int len = s.size();
        bool isFirst = true;
        while (isFirst || s[from] == s[from-1] && from <= len-1) {
            isFirst = false;
            from++;
        }

        return from-1;;
    }

    int countBinarySubstrings(string s) {
        int len = s.size();

        int i1 = 0;
        int j1 = 0;
        int i2 = 0;
        int j2 = 0;

        int l1 = 0;
        int l2 = 0;

        int res = 0;
        while (1) {
            j1 = findDiff(s, i1);
            l1 = j1-i1+1;
            if (j1 >= len-1) {
                break;
            }

            i2 = j1+1;
            j2 = findDiff(s, i2);
            l2 = j2-i2+1;
            i1 = j1+1;

            res += min(l1, l2);
            if (j2 >= len-1) {
                break;
            }
        }

        return res;
    }
};
