class Solution {
public:
    bool repeatedSubstringPattern(string str) {
        int len = str.size();
        if (len == 1) {
            return false;
        }
        for (int i = 1; i <= len/2; i++) {  // 长度
            if (len % i != 0) {
                continue;
            }

            int segment_num = len/i;
            int ok = 1;
            for (int j = 0; j < i; j++) {   //  0-i 是字符串
                if (ok == 0) {
                    break;
                }
                for (int k = 1; k < segment_num; k++) {
                    if (str[k*i+j] != str[j]) {
                        ok = 0;
                        break;
                    }
                }
            }

            if (ok == 1) {                
                return true;
            }
        }

        return false;
    }
};
