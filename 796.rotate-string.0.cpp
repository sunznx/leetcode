class Solution {
public:
    bool rotateString(string A, string B) {
        A = A + A;
        
        return A.find(B) != -1 && A.size() == B.size() * 2;
    }
};
