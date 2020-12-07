class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        return !(rec1[0] >= rec2[2]    // rec1完全在rec2右侧
                 || rec1[2] <= rec2[0] // rec1完全在rec2左侧
                 || rec1[1] >= rec2[3] // rec1完全在rec2上方
                 || rec1[3] <= rec2[1] // rec1完全在rec2下方
                 || rec1[0] == rec1[2] // rec1为一条竖线
                 || rec1[1] == rec1[3] // rec1为一条横线
                 || rec2[0] == rec2[2] // rec2为一条竖线
                 || rec2[1] == rec2[3] // rec2为一条横线
            );
    }
};