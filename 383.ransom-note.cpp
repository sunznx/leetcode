// CreateTime: 2019-11-28 15:58:05
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> m(26);

        int len;
        
        len = magazine.size();
        for (int i = 0; i < len; i++) {
            m[magazine[i]-'a'] += 1;
        }
        
        len = ransomNote.size();
        for (int i = 0; i < len; i++) {
            m[ransomNote[i]-'a'] -= 1;
            
            if (m[ransomNote[i]-'a'] < 0) {
                return false;
            }
        }
        
        return true;
    }
};
