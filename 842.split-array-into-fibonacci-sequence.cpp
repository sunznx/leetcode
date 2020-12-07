// CreateTime: 2020-12-08 01:04:11
class Solution {
public:
    vector<int> ans;
    vector<int> aux;
    string maxString;

    vector<int> splitIntoFibonacci(string S) {
        maxString = to_string(INT_MAX);
        dfs(S);
        return ans;
    }

    bool lessThanMax(string &sub) {
        return (sub.size() < maxString.size()) ||
            (sub.size() == maxString.size() && sub <= maxString);
    }

    void dfs(string &s, int pos = 0) {
        if (ans.size()) {
            return;
        }

        if (pos == s.size()) {
            if (aux.size() >= 3) {
                ans = aux;
            }
            return;
        }

        if (aux.size() <= 1) {
            if (s[pos] == '0') {
                aux.push_back(0);
                dfs(s, pos+1);
                aux.pop_back();
                return;
            }

            string sub;
            for (int i = pos; i < s.size(); i++) {
                sub += s[i];
                if (lessThanMax(sub)) {
                    aux.push_back(stol(sub));
                    dfs(s, i+1);
                    aux.pop_back();
                }
            }
            return;
        }

        auto num2 = (long)(aux[aux.size()-1]);
        auto num1 = (long)(aux[aux.size()-2]);
        auto expectValue = long(num1 + num2);
        auto expectString = to_string(expectValue);

        if (!lessThanMax(expectString)) {
            return;
        }

        if (s.substr(pos, expectString.size()) == expectString) {
            aux.push_back(expectValue);
            dfs(s, pos+expectString.size());
            aux.pop_back();
        }
    }
};
