// CreateTime: 2019-11-26 03:20:43
class Solution {
public:
    vector<int> parent;
    vector<vector<int>> m;

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void merge(int p1, int p2) {
        if (p1 == p2) {
            return;
        }
        parent[p2] = p1;

        for (int i = 0; i < 26; i++) {
            m[p1][i] += m[p2][i];
        }
    }

    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int len = s.size();
        parent.resize(len);
        m.resize(len);
        for (int i = 0; i < len; i++) {
            m[i].resize(26);
        }

        for (int i = 0; i < len; i++) {
            parent[i] = i;
            m[i][s[i]-'a'] += 1;
        }

        for (int i = 0; i < pairs.size(); i++) {
            int first = pairs[i][0];
            int second = pairs[i][1];

            int p1 = find(first);
            int p2 = find(second);
            merge(p1, p2);
        }

        string res = s;
        for (int i = 0; i < len; i++) {
            int p = find(i);
            for (int k = 0; k < 26; k++) {
                if (m[p][k] > 0) {
                    res[i] = k + 'a';
                    m[p][k]--;
                    break;
                }
            }
        }
        return res;
    }
};