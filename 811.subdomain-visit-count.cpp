class Solution {
public:
    map<string, int> m;
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        int len = cpdomains.size();
        for (int i = 0; i < len; i++) {

            int count;
            char buff[100] = {};

            sscanf(cpdomains[i].c_str(), "%d %s", &count, buff);
            vector<string> s = mysplit(buff, '.');
            for (int j = 0; j < s.size(); j++) {
                if (m.find(s[j]) != m.end()) {
                    m[s[j]] += count;
                } else {
                    m[s[j]] = count;
                }
            }
        }

        vector<string> res;


        for (auto iter = m.begin(); iter != m.end(); iter++) {
            res.push_back(to_string(iter->second) + " " + (string)(iter->first));
        }

        return res;
    }

    vector<string> mysplit(char *s, char c) {
        vector<string> res;
        string str = "";
        while (*s) {
            if (*s == c) {
                if (str.size()) {
                    for (int i = 0; i < res.size(); i++) {
                        res[i] = res[i] + "." + str;
                    }
                    res.push_back(str);
                    str = "";
                }
            } else {
                str += *s;
            }
            s++;
        }
        if (str.size()) {
            for (int i = 0; i < res.size(); i++) {
                res[i] = res[i] + "." + str;
            }
            res.push_back(str);
        }

        return res;
    }
};
