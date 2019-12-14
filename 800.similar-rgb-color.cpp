// CreateTime: 2019-12-14 13:16:03
class Solution {
public:
    string similarRGB(string color) {
        string AB = "0x" + color.substr(1, 2);
        string CD = "0x" + color.substr(3, 2);
        string EF = "0x" + color.substr(5, 2);

        int ab = stoi(AB, nullptr, 0);
        int cd = stoi(CD, nullptr, 0);
        int ef = stoi(EF, nullptr, 0);

        int x = search(ab);
        int y = search(cd);
        int z = search(ef);

        char res[8];
        sprintf(res, "#%02x%02x%02x", x, y, z);

        return string(res);
    }

    inline int search(int n) {
        int m = n/17;
        int m1 = m-1;
        int m2 = m+1;

        int minv = m;
        if (m1 >= 0 && abs(n-m1*17) < abs(n-minv*17)) {
            minv = m1;
        }
        if (m2 <= 15 && abs(n-m2*17) < abs(n-minv*17)) {
            minv = m2;
        }
        return minv * 17;
    }

};
