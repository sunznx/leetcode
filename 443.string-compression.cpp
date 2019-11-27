// CreateTime: 2019-11-26 23:29:11
class Solution {
public:
    int compress(vector<char>& chars) {
        int i = 0;
        int cnt = 0;

        while (i < chars.size() || cnt) {
            if (i < chars.size() && (cnt == 0 || chars[i] == chars[i-1])) {
                cnt += 1;
                i += 1;
            } else {
                if (cnt > 1) {
                    chars.erase(chars.begin()+i-cnt+1, chars.begin()+i);
                    i -= cnt-1;

                    string cntStr = to_string(cnt);
                    for (int k = 0; k < cntStr.size(); k++) {
                        chars.insert(chars.begin()+i+k, cntStr[k]);
                    }
                    i += cntStr.size();
                }
                cnt = 0;
            }
        }

        return chars.size();
    }
};
