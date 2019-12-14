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
        
        int x = 17 * search(ab);
        int y = 17 * search(cd);
        int z = 17 * search(ef);
        
        char res[8];
        sprintf(res, "#%02x%02x%02x", x, y, z);

        return string(res);
    }
    
    int search(int n) {
        int l = 0x0;
        int r = 0xf;
        
        while (l < r) {
            int mid = (l+r) / 2;
            if (n <= mid * 17) {
                r = mid;
            } else {
                l = mid+1;
            }
        }
        
        if (l > 0 && abs(n - l*17) > abs(n-(l-1)*17)) {
            return l-1;
        }
        return l;
    }
    
};
