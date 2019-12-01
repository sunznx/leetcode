// CreateTime: 2019-12-01 13:22:08
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int len = s.size();
        unordered_map<string, int> m;
        
        vector<string> res;
        for (int i = 0; i <= len-10; i++) {
            string sub = s.substr(i, 10);
            if (m[sub] == 1) {
                res.push_back(sub);                
            }
            m[sub] += 1;
        }
        return res;
    }
};