// CreateTime: 2020-12-04 00:07:54
class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> countMap;
        unordered_map<int, int> endMap;
        for (int i = 0; i < nums.size(); i++) {
            auto x = nums[i];
            countMap[x]++;
        }

        for (int i = 0; i < nums.size(); i++) {
            auto x = nums[i];
            if (countMap[x] == 0) {
                continue;
            }

            // 寻找是否有 x-1 作为结尾的序列
            if (endMap[x-1] > 0) {
                countMap[x]--;
                endMap[x-1]--;
                endMap[x]++;
                continue;
            }

            // 没有找到 x-1 作为结尾的队列
            auto x1 = countMap[x+1];
            auto x2 = countMap[x+2];

            if (x1 <= 0 || x2 <= 0) {
                return false;
            }

            countMap[x]--;
            countMap[x+1]--;
            countMap[x+2]--;
            endMap[x+2]++;
        }

        return true;
    }
};
