// CreateTime: 2020-12-02 07:42:43
class Solution {
public:
    string removeDuplicateLetters(string s) {
        int len = s.size();

        vector<int> m(256);
        vector<bool> in(256);

        for (int i = 0; i < len; i++) {
            auto c = s[i];
            m[c]++;
        }

        deque<char> q;

        for (int i = 0; i < len; i++) {
            auto c = s[i];
            m[c]--;

            if (in[c] == false) {
                while (q.size() && m[q.back()] && c < q.back()) {
                    in[q.back()] = false;
                    q.pop_back();
                }
                in[c] = true;
                q.push_back(c);
            }
        }

        string ans;
        while (q.size()) {
            ans.push_back(q.front());
            q.pop_front();
        }
        return ans;
    }
};
