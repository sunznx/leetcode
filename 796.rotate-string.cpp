class Solution {
public:
    bool rotateString(string A, string B) {
        int len1 = A.size();
        int len2 = B.size();

        if (len1 != len2) {
            return false;
        }

        if (len1 == 0 && len2 == 0) {
            return true;
        }

        for (int i = 0; i < len1; i++) {
            if (A[i] == B[0]) {
                if (checkMatch(A, B, i)) {
                    return true;
                }
            }
        }

        return false;
    }

    bool checkMatch(string A, string B, int from) {
        int len1 = A.size();
        int len2 = B.size();

        for (int i = 0; i < len2; i++) {
            from = from % len1;
            if (A[from] == B[i]) {
                from++;
            } else {
                return false;
            }
        }

        return true;
    }
};
