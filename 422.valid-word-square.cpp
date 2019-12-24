// CreateTime: 2019-12-24 14:40:27
class Solution {
public:
    bool validWordSquare(vector<string>& words) {
        int len = words.size();
        for (int i = 0; i < len; i++) {
            string word1 = words[i];
            string word2 = "";
            for (int j = 0; j < len && i < words[j].size(); j++) {
                word2 += words[j][i];
            }

            if (word1 != word2) {
                return false;
            }
        }

        return true;
    }
};
