class Solution {
public:

    int found(vector<int> &numbers, int L, int R, int target) {
        while (L <= R) {
            int mid = (L + R) / 2;

            if (numbers[mid] == target) {
                return mid;
            } else if (numbers[mid] < target) {
                L = mid + 1;
            } else if (numbers[mid] > target) {
                R = mid - 1;
            }
        }

        return -1;
    }

    vector<int> twoSum(vector<int>& numbers, int target) {
        int len = numbers.size();

        vector<int> res(2, 0);

        for (int i = 0; i < len-1; i++) {
            int index = found(numbers, i+1, len-1, target-numbers[i]);
            if (index != -1) {
                res[0] = i+1;
                res[1] = index+1;
                break;
            }
        }

        return res;
    }
};
