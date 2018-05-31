class Solution {
public:
    char charset[27][10] = {
        ".-",
        "-...",
        "-.-.",
        "-..",
        ".",
        "..-.",
        "--.",
        "....",
        "..",
        ".---",
        "-.-",
        ".-..",
        "--",
        "-.",
        "---",
        ".--.",
        "--.-",
        ".-.",
        "...",
        "-",
        "..-",
        "...-",
        ".--",
        "-..-",
        "-.--",
        "--.."
    };

    int uniqueMorseRepresentations(vector<string>& words) {
        int len = words.size();
        if (len == 0) {
            return 0;
        }

        vector<string> v;
        for (int i = 0; i < len; i++) {
            string w = words[i];
            string s = "";
            for (int j = 0; j < w.size(); j++) {
                s += charset[words[i][j] - 'a'];
            }
            v.push_back(s);
        }
        sort(v.begin(), v.end());

        int res = 1;
        for (int i = 1; i < v.size(); i++) {
            if (v[i] != v[i-1]) {
                res++;
            }
        }

        return res;
    }
};
