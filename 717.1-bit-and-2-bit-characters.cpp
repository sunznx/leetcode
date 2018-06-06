class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        return isOneBitCharacter(bits, 0, false, false);
    }

    bool isOneBitCharacter(vector<int>& bits, int from, bool found0, bool found1) {
        int len = bits.size();
        for (int i = from; i < len; i++) {
            if (bits[i] == 1) {
                if (bits[i+1] == 0 && i+1 == len-1) {
                    return false;
                }

                i += 1;
            }
        }

        return true;
    }
};
