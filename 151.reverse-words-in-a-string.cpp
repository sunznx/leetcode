class Solution {
public:
    void reverseWords(string &s) {
        while (s.size() && s[0] == ' ') {
            s.erase(s.begin());
        }
        while (s.size() && s[s.size()-1] == ' ') {
            s.erase(s.end()-1);
        }

        if (s.size() == 0) {
            return;
        }

        auto arr = split(' ', s);

        auto iter = arr.begin();
        while (iter != arr.end()) {
            if (iter->size() == 0) {
                arr.erase(iter);
                continue;
            }
            iter++;
        }

        reverse(arr.begin(), arr.end());
        s = join(arr);
    }

    vector<string> split(char delim, const string& s) {
        stringstream ss(s);
        string item;
        vector<string> elems;
        while (getline(ss, item, delim)) {
            elems.push_back(item);
        }
        return elems;
    }

    string join(vector<string>& v) {
        string res = "";
        for (int i = 0; i < v.size(); i++) {
            if (i == 0) {
                res = v[0];
            } else {
                res += " " + v[i];
            }
        }

        return res;
    }
};
