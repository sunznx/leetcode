// CreateTime: 2020-12-04 07:38:55
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int l = 0;
        int r = letters.size()-1;

        while (l < r) {
            int m = (l+r+1) / 2;

            if (letters[m] > target) {
                r = m-1;
            } else if (letters[m] <= target) {
                l = m;
            }
        }

        if (letters[l] > target) {
            return letters[l];
        }

        int k = (l+1) % letters.size();
        return letters[k];
    }
};
