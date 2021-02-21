// CreateTime: 2021-02-21 10:30:30
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans = "";

        int i = 0;
        int j = 0;
        int len1 = word1.size();
        int len2 = word2.size();

        for (int k = 0; k < len1+len2; k++) {
            if (i == len1) {
                ans = ans + word2.substr(j);
                break;
            } else if (j == len2) {
                ans = ans + word1.substr(i);
                break;
            } else if (k % 2 == 0) {
                ans = ans + word1[i++];
            } else {
                ans = ans + word2[j++];
            }
        }

        return ans;
    }
};