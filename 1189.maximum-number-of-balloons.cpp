// CreateTime: 2019-12-14 16:05:48
class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int b = 0;
        int a = 0;
        int l = 0;
        int o = 0;
        int n = 0;

        int len = text.size();
        for (int i = 0; i < len; i++) {
            if (text[i] == 'a') {
                a++;
            }
            if (text[i] == 'b') {
                b++;
            }
            if (text[i] == 'l') {
                l++;
            }
            if (text[i] == 'o') {
                o++;
            }
            if (text[i] == 'n') {
                n++;
            }
        }

        int ans = len;
        ans = min(ans, a);
        ans = min(ans, b);
        ans = min(ans, l/2);
        ans = min(ans, o/2);
        ans = min(ans, n);

        return ans;
    }
};
