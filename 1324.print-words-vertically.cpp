// CreateTime: 2020-01-28 00:31:15
class Solution {
public:
    vector<string> printVertically(string s) {
        vector<string> res;

        vector<string> arr;

        int k = 0;
        string v;
        while (k < s.size()) {
            if (s[k] != ' ') {
                v.push_back(s[k]);
            }
            if (s[k] == ' ' || k == s.size()-1) {
                arr.push_back(v);
                v = "";
            }
            k++;
        }

        int len = arr.size();
        vector<int> used(len);

        while (true) {
            bool ok = false;
            string v;
            for (int i = 0; i < len; i++) {
                auto &u = used[i];
                if (u <= arr[i].size()-1) {
                    ok = true;
                    v.push_back(arr[i][u++]);
                } else {
                    v.push_back(' ');
                }
            }

            while (v.size() && v[v.size()-1] == ' ') {
                v.erase(v.begin()+v.size()-1);
            }

            if (ok) {
                res.push_back(v);
            } else {
                break;
            }
        }

        return res;
    }
};
