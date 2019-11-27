// CreateTime: 2019-11-27 11:29:06
class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int i = 0;
        while (i < arr.size()) {
            if (arr[i] == 0) {
                arr.insert(arr.begin() + i, 0);
                arr.pop_back();
                i += 2;
            } else {
                i++;
            }
        }
    }
};