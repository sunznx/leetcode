// CreateTime: 2020-11-24 01:15:04
/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */
class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int l = 0;
        int r = mountainArr.length()-1;
        while (l < r) {
            int m = (l+r) / 2;
            if (mountainArr.get(m) < mountainArr.get(m + 1)) {
                l = m + 1;
            } else {
                r = m;
            }
        }

        auto peak = l;
        auto findL = searchAsc(target, mountainArr, 0, peak);
        if (findL != -1) {
            return findL;
        }
        return searchDesc(target, mountainArr, peak+1, mountainArr.length()-1);
    }

    int searchAsc(int target, MountainArray &mountainArr, int l, int r) {
        while (l < r) {
            int m = (l+r+1) / 2;
            auto x = mountainArr.get(m);
            if (target >= x) {
                l = m;
            } else if (target < x) {
                r = m-1;
            }
        }

        if (mountainArr.get(l) == target) {
            return l;
        }
        return -1;
    }

    int searchDesc(int target, MountainArray &mountainArr, int l, int r) {
        while (l < r) {
            int m = (l+r+1) / 2;
            auto x = mountainArr.get(m);
            if (target <= x) {
                l = m;
            } else if (target > x) {
                r = m-1;
            }
        }

        if (mountainArr.get(l) == target) {
            return l;
        }
        return -1;
    }
};
