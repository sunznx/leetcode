class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        int i = 1;
        int len = s.size();
        vector<vector<int>> res;

        int count = 1;
        int from = 0;
        while (i < len) {
            if (s[i] == s[i-1]) {
                count++;
            }

            if (s[i] != s[i-1]) {
                if (count >= 3) {
                    vector<int> v(2);
                    v[0] = from;
                    v[1] = i-1;
                    res.push_back(v);
                }
                count = 1;
                from = i;
            }

            if (i == len-1) {
                if (count >= 3) {
                    vector<int> v(2);
                    v[0] = from;
                    v[1] = i;
                    res.push_back(v);
                }
            }

            i++;
        }

        return res;
    }
};
