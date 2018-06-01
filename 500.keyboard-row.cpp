class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> res;
        int len = words.size();
        int charmap[27] = {0};
        charmap['q' - 'a'] = 0;
        charmap['w' - 'a'] = 0;
        charmap['e' - 'a'] = 0;
        charmap['r' - 'a'] = 0;
        charmap['t' - 'a'] = 0;
        charmap['y' - 'a'] = 0;
        charmap['u' - 'a'] = 0;
        charmap['i' - 'a'] = 0;
        charmap['o' - 'a'] = 0;
        charmap['p' - 'a'] = 0;

        charmap['a' - 'a'] = 1;
        charmap['s' - 'a'] = 1;
        charmap['d' - 'a'] = 1;
        charmap['f' - 'a'] = 1;
        charmap['g' - 'a'] = 1;
        charmap['h' - 'a'] = 1;
        charmap['j' - 'a'] = 1;
        charmap['k' - 'a'] = 1;
        charmap['l' - 'a'] = 1;

        charmap['z' - 'a'] = 2;
        charmap['x' - 'a'] = 2;
        charmap['c' - 'a'] = 2;
        charmap['v' - 'a'] = 2;
        charmap['b' - 'a'] = 2;
        charmap['n' - 'a'] = 2;
        charmap['m' - 'a'] = 2;

        for (int i = 0; i < len; i++) {
            string cur = words[i];
            bool ok = true;


            int firstLine;
            int curLine;
            if ('A' <= cur[0] && cur[0] <= 'Z') {
                firstLine = charmap[cur[0] - 'A'];
            } else {
                firstLine = charmap[cur[0] - 'a'];
            }

            for (int j = 1; j < cur.size(); j++) {
                if ('A' <= cur[j] && cur[j] <= 'Z') {
                    curLine = charmap[cur[j] - 'A'];
                } else {
                    curLine = charmap[cur[j] - 'a'];
                }

                if (firstLine != curLine) {
                    ok = false;
                    break;
                }
            }

            if (ok) {
                res.push_back(cur);
            }
        }

        return res;
    }
};
