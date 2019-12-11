// CreateTime: 2019-12-11 14:31:02
class Solution {
public:
    bool ok = true;

    bool isValidSerialization(string preorder) {
        auto arr = split(',', preorder);
        auto tot = walk(0, arr);
        if (ok) {
            return tot == arr.size();
        }
        return ok;
    }

    int walk(int idx, vector<string> &arr) {
        if (!ok) {
            return 0;
        }

        if (idx == arr.size()-2 || idx == arr.size()-1) {
            if (arr[idx] != "#") {
                ok = false;
                return 0;
            } else {
                return 1;
            }
        }

        if (arr[idx] != "#" && !(idx+2 <= arr.size()-1)) {
            ok = false;
            return 0;
        }

        if (arr[idx] == "#") {
            return 1;
        }

        int l = walk(idx+1, arr);
        int r = walk(idx+1+l, arr);
        return l + r + 1;
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
};
