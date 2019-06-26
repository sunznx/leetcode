class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int P) {

        sort(tokens.begin(), tokens.end());

        auto score = 0;
        auto n = tokens.size();
        auto i = 0;
        auto j = n-1;

        while (n > 0) {
            if (P >= tokens[i]) {
                P -= tokens[i];
                score += 1;
                n -= 1;
                i += 1;
                continue;
            }

            if (P < tokens[i] && score > 0 && n >= 3) {
                P += tokens[j];
                score -= 1;
                n -= 1;
                j -= 1;
                continue;
            }

            break;
        }

        return score;
    }
};
