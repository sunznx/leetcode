// CreateTime: 2019-12-13 19:20:01
class Solution {
public:
    int calculateTime(string keyboard, string word) {
        vector<int> m(26);
        for (int i = 0; i < 26; i++) {
            m[keyboard[i]-'a'] = i;
        }
        
        int ans = 0;

        int len = word.size();
        int pre = 0;
        for (int i = 0; i < len; i++) {
            ans += abs(m[word[i]-'a'] - pre);
            pre = m[word[i]-'a'];
        }
        
        return ans;
    }
};
