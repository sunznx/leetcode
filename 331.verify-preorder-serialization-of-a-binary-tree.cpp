// CreateTime: 2020-12-03 15:05:44
class Solution {
public:
    bool isValidSerialization(string preorder) {
        auto slots = 1;
        auto arr = split(preorder, ',');

        for (int i = 0; i < arr.size(); i++) {
            auto x = arr[i];
            slots--;

            if (slots < 0) {
                return false;
            }

            if (x != "#") {
                slots += 2;
            }
        }
        
        return slots == 0;
    }

    vector<string> split(string &s, char x) {
        vector<string> ans;
        string sub = "";
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != x) {
                sub.push_back(s[i]);
            }

            if (s[i] == x || i == s.size()-1) {
                ans.push_back(sub);
                sub = "";
            }
        }
        return ans;
    }
};
