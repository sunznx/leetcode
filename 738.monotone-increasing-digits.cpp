// CreateTime: 2020-12-15 02:54:57
class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        auto str = to_string(N);

        auto maxIdx = 0;
        for (int i = 0; i < str.size()-1; i++) {
            if (str[i] > str[maxIdx]) {
                maxIdx = i;
            }

            if (str[i] > str[i+1]) {
                str[maxIdx] -= 1;
                for (int j = maxIdx+1; j < str.size(); j++) {
                    str[j] = '9';
                }
                break;
            }
        }

        return stoi(str);
    }
};
