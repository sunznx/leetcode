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

            auto I = i+same;
            auto J = j+same;

            if (I == len1) {
                ans += word2[j++];
                same = 0;
            } else if (J == len2) {
                ans += word1[i++];
                same = 0;
            } else if (word1[I] > word2[J]) {
                ans += word1[i++];
                same = 0;
            } else if (word1[I] < word2[J]) {
                ans += word2[j++];
                same = 0;
            } else {
                same++;
            }
        }

        return ans;
    }
};
