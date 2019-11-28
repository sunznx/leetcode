// CreateTime: 2019-11-28 11:25:30
class Solution {
public:
    string defangIPaddr(string address) {
        int len = address.size();
        string res(len+6, ' ');
        int k = 0;
        for (int i = 0; i < len; i++) {
            if (address[i] == '.') {
                res[k++] = '[';
                res[k++] = '.';
                res[k++] = ']';
            } else {
                res[k++] = address[i];
            }
        }
        
        return res;
    }
};
