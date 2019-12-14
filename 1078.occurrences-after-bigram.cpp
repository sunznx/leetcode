// CreateTime: 2019-12-14 16:24:58
class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        vector<string> res;

        auto arr = split(' ', text);
        int len = arr.size();
        for (int i = 2; i < len; i++) {
            if (arr[i-2] == first && arr[i-1] == second) {
                res.push_back(arr[i]);
            }
        }

        return res;
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
