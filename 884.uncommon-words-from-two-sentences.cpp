class Solution {
public:
    map<string, int> m;

    vector<string> split(char delim, const string& s) {
        stringstream ss(s);
        string item;
        vector<string> elems;
        while (getline(ss, item, delim)) {
            elems.push_back(item);
        }
        return elems;
    }

    vector<string> uncommonFromSentences(string A, string B) {
        vector<string> res;
        
        auto arr1 = split(' ', A);
        auto arr2 = split(' ', B);
        
        for (int i = 0; i < arr1.size(); i++) {
            m[arr1[i]] += 1;
        }
        for (int i = 0; i < arr2.size(); i++) {
            m[arr2[i]] += 1;
        }
        
        for (auto iter = m.begin(); iter != m.end(); iter++) {
            if (iter->second == 1) {
                res.push_back(iter->first);
            }
        }
        
        return res;
    }
};
