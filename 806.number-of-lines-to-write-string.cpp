// CreateTime: 2019-12-31 11:03:41
class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string S) {
        int line = 1;
        int width = 0;

        int len = S.size();
        int v = 0;
        for (int i = 0; i < len; i++) {
            v = v + widths[S[i]-'a'];
            if (v > 100) {
                line = line + 1;
                v = widths[S[i]-'a'];
            }
            width = v;
        }
        
        return {line, width};
    }
};
