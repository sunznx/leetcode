// CreateTime: 2021-02-18 17:03:58
class Solution {
public:
    int minAbsDifference(vector<int>& nums, int goal) {
        int len = nums.size();

        auto len1 = len/2;
        auto len2 = len-len1;

        vector<int> arr1(1<<len1);
        vector<int> arr2(1<<len2);

        for (int i = 0; i < (1<<len1); i++) {
            for (int j = 0; j < len1; j++) {
                if ((i & (1<<j)) != 0) {
                    arr1[i] = arr1[(i-(1<<j))] + nums[j];
                    break;
                }
            }
        }

        for (int i = 0; i < (1<<len2); i++) {
            for (int j = 0; j < len2; j++) {
                if ((i & (1<<j)) != 0) {
                    arr2[i] = arr2[(i-(1<<j))] + nums[len1+j];
                    break;
                }
            }
        }

        sort(arr1.begin(), arr1.end());
        sort(arr2.begin(), arr2.end());

        int ans = INT_MAX;

        for (auto &x: arr1) {
            ans = min(ans, abs(x-goal));
        }

        for (auto &x: arr2) {
            ans = min(ans, abs(x-goal));
        }

        int i = 0;
        int j = arr2.size()-1;
        while (i < arr1.size() && j >= 0) {
            int x = arr1[i] + arr2[j];
            ans = min(ans, abs(x-goal));

            if (x > goal) {
                j--;
            } else {
                i++;
            }
        }

        return ans;
    }
};
