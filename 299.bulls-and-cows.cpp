class Solution {
public:
    string getHint(string secret, string guess) {
        int A = 0;
        int B = 0;
        int len1 = secret.size();
        int len2 = guess.size();
        int len = min(len1, len2);

        for (int i = 0; i < len; i++) {
            if (secret[i] == guess[i]) {
                A++;
            }
        }

        sort(secret.begin(), secret.end());
        sort(guess.begin(), guess.end());

        int index1 = 0;
        int index2 = 0;
        while (1) {
            if (index1 == len || index2 == len) {
                break;
            }

            if (secret[index1] < guess[index2]) {
                index1++;
            } else if (secret[index1] > guess[index2]) {
                index2++;
            } else {
                B++;
                index1++;
                index2++;
            }
        }
        B = B - A;

        return to_string(A) + "A" + to_string(B) + "B";
    }
};
