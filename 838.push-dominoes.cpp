// CreateTime: 2020-11-24 12:54:55
class Solution {
public:
    string pushDominoes(string dominoes) {
        int len = dominoes.size();

        queue<int> q;

        for (int i = 0; i < len; i++) {
            if (dominoes[i] != '.') {
                q.push(i);
            }
        }

        while (!q.empty()) {
            unordered_map<int, char> m;
            while (!q.empty()) {
                int x = q.front();
                q.pop();
                m[x] = dominoes[x];
            }

            for (auto &t: m) {
                auto x = t.first;
                if (dominoes[x] == 'L' && x-1 >= 0 && dominoes[x-1] == '.') {
                    if (m.find(x-2) == m.end() || m[x-2] != 'R') {
                        dominoes[x-1] = 'L';
                        q.push(x-1);
                    }
                }

                if (dominoes[x] == 'R' && x+1 <= len-1 && dominoes[x+1] == '.') {
                    if (m.find(x+2) == m.end() || m[x+2] != 'L') {
                        dominoes[x+1] = 'R';
                        q.push(x+1);
                    }
                }
            }
        }

        return dominoes;
    }
};