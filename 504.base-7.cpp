class Solution {
public:
    string convertToBase7(int num) {
        if (num == 0) {
            return string("0");
        }
        
        bool isSigned = false;
        if (num < 0) {
            isSigned = true;
            num = -num;
        }

        string res = "";
        while (num) {
            int mod = num % 7;
            num = num / 7;
            res.insert(0, 1, mod + '0');
        }
        
        if (isSigned) {
            res.insert(0, 1, '-');
        }
        
        return res;
    }
};
