// CreateTime: 2020-11-24 12:54:55
class Solution {
public:
    string pushDominoes(string dominoes) {
        int len = dominoes.size();

        queue<pair<int, char>> q;

        for (int i = 0; i < len; i++) {
            if (dominoes[i] != '.') {
                q.push({i, dominoes[i]});
            }
        }

        string ans = dominoes;

        while (q.size()) {
            unordered_map<int, char> m;

            int k = q.size();
            while (k--) {
                auto top = q.front();
                q.pop();
                m[top.first] = top.second;
            }

            for (auto &t: m) {
                auto x = t.first;
                auto c = t.second;

                if (c == 'L' && x-1 >= 0 && ans[x-1] == '.') {
                    if (m.find(x-2) == m.end() || m[x-2] != 'R') {
                        ans[x-1] = 'L';
                        q.push({x-1, 'L'});
                    }
                }

                if (c == 'R' && x+1 <= len-1 && ans[x+1] == '.') {
                    if (m.find(x+2) == m.end() || m[x+2] != 'L') {
                        ans[x+1] = 'R';
                        q.push({x+1, 'R'});
                    }
                }
            }

        }

        return ans;
    }
};