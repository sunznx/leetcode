// CreateTime: 2021-04-06 01:46:44
class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int l1 = max(A, E);
        int l2 = max(B, F);
        int r1 = min(C, G);
        int r2 = min(D, H);
        int S = max(r1 - l1, 0) * max(r2 - l2, 0);
        return (C-A)*(D-B) + (G-E)*(H-F) - S;
    }
};