// CreateTime: 2021-02-18 15:49:32
class Solution {
public:
    string largestMerge(string word1, string word2) {
        string ans = "";

        int len1 = word1.size();
        int len2 = word2.size();

        auto i = 0;
        auto j = 0;
        auto same = 0;
        while (ans.size() < len1+len2) {
            if (i == len1) {
                ans = ans + word2.substr(j);
                continue;
            }

            if (j == len2) {
                ans = ans + word1.substr(i);
                continue;
            }

            if (word1.substr(i) > word2.substr(j)) {
                ans += word1[i++];
            } else {
                ans += word2[j++];
            }
        }

        return ans;
    }
};
