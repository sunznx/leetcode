// CreateTime: 2020-12-08 12:17:15
class Solution {
public:
    string removeDuplicates(string S) {
        string ans;

        for (int i = 0; i < S.size(); i++) {
            ans.push_back(S[i]);

            while (ans.size() >= 2) {
                auto c1 = ans[ans.size()-1];
                auto c2 = ans[ans.size()-2];
                if (c1 != c2) {
                    break;
                }

                ans.pop_back();
                ans.pop_back();
            }
        }

        return ans;
    }
};
