// CreateTime: 2019-12-14 07:20:11
class Solution {
public:
    vector<int> diStringMatch(string S) {
        vector<int> ans;
        
        int len = S.size();
        int low = 0;
        int height = len;
        for (int i = 0; i < len; i++) {
            if (S[i] == 'I') {
                ans.push_back(low++);
            } else {
                ans.push_back(height--);
            }
        }

        ans.push_back(low);
        return ans;
    }
};
