// CreateTime: 2019-12-05 22:02:03
class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int len = words.size();
        
        int d = len+1;
        int v1 = -1;
        int v2 = -1;
        
        for (int i = 0; i < len; i++) {
            if (words[i] == word1) {
                v1 = i;
            }
            
            if (words[i] == word2) {
                v2 = i;
            }
            
            if (v1 >= 0 && v2 >= 0) {
                d = min(d, abs(v2-v1));                
            }
        }
        return d;
    }
};
