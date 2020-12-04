// CreateTime: 2020-12-04 08:23:30
class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        bool foundUp = false;
        bool foundDown = false;

        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] > arr[i-1]) {
                if (foundDown) {
                    return false;
                }
                foundUp = true;
            } else if (arr[i] < arr[i-1]) {
                if (!foundUp) {
                    return false;
                }
                foundDown = true;
            } else {
                return false;
            }
        }

        return foundUp && foundDown;
    }
};
