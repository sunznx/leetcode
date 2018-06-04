class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int len = letters.size();

        for (int i = 0; i < len; i++) {
            if (letters[i] > target) {
                return letters[i];
            }
        }
        
        return letters[0];
    }
};
