// CreateTime: 2021-02-18 15:49:32
class Solution {
public:
    string largestMerge(string word1, string word2) {
        string ans = "";

        while (word1.size() || word2.size()) {
            if (word1.size() == 0) {
                ans = ans + word2;
                word2.clear();
            } else if (word2.size() == 0) {
                ans = ans + word1;
                word1.clear();
            } else if (word1 > word2) {
                ans = ans + word1[0];
                word1 = word1.substr(1);
            } else {
                ans = ans + word2[0];
                word2 = word2.substr(1);
            }
        }

        return ans;
    }
};
