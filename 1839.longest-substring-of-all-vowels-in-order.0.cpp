// CreateTime: 2021-04-26 15:03:46
class Solution {
public:
    enum STATE {
        STATE_INIT,
        STATE_A,
        STATE_E,
        STATE_I,
        STATE_O,
        STATE_U,
    };

    int longestBeautifulSubstring(string word) {
        unordered_map<STATE, unordered_map<char, STATE>> m;
        m[STATE_INIT] = {
            {'a', STATE_A}
        };
        m[STATE_A] = {
            {'a', STATE_A},
            {'e', STATE_E}
        };
        m[STATE_E] = {
            {'e', STATE_E},
            {'i', STATE_I}
        };
        m[STATE_I] = {
            {'i', STATE_I},
            {'o', STATE_O}
        };
        m[STATE_O] = {
            {'o', STATE_O},
            {'u', STATE_U}
        };
        m[STATE_U] = {
            {'u', STATE_U}
        };

        STATE state = STATE_INIT;
        int k = 0;
        int ans = 0;
        for (auto x: word) {
            if (m[state].find(x) == m[state].end()) {
                state = STATE_INIT;
                k = 0;
            }

            if (m[state].find(x) != m[state].end()) {
                state = m[state][x];
                k++;
            }

            if (state == STATE_U) {
                ans = max(ans, k);
            }
        }

        return ans;
    }
};
