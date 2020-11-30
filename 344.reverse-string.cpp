// CreateTime: 2020-12-01 03:26:12
class Solution {
public:
    void reverseString(vector<char>& s) {
        int l = 0;
        int r = s.size()-1;
        
        while (l < r) {
            swap(s[l++], s[r--]);
        }
    }
};
