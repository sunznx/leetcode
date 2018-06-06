class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int len = bits.size();
        for (int i = 0; i < len; i++) {
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
