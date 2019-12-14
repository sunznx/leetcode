// CreateTime: 2019-12-14 16:11:20
class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int k = 0;
        while (k < typed.size()) {
            if (name[k] == typed[k]) {
                k++;
            } else if (k > 0 && typed[k] == typed[k-1]) {
                typed.erase(typed.begin()+k);
            } else {
                return false;
            }
        }
        return typed.size() == name.size();
    }
};
