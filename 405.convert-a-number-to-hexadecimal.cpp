class Solution {
public:
    string toHex(int num) {
        if (num == 0) {
            return string("0");
        }

        if (num == INT_MIN) {
            return string("80000000");
        }

        bool isSign = false;
        if (num < 0) {
            isSign = true;
            num = ((~num) ^ 0xFFFFFFF);
        }

        string res = "";
        while (num) {
            int mod = num % 16;
            num = num / 16;

            char c;
            if (0 <= mod && mod <= 9) {
                c = mod + '0';
            } else {
                c = mod - 10 + 'a';
            }

            res.insert(0, 1, c);
        }
        if (isSign) {
            int prepend1 = 8-res.size();
            for (int i = 0; i < prepend1; i++) {
                res.insert(0, 1, 'f');
            }
        }

        return res;
    }
};
