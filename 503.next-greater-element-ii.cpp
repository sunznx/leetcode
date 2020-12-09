// CreateTime: 2020-12-05 02:18:51
class Solution {
public:
    typedef pair<int, int> PII;

    vector<int> nextGreaterElements(vector<int>& nums) {
        int len = nums.size();

        deque<PII> que;
        vector<int> ans(len);
        for (int i = 2*len-1; i >= 0; i--) {
            auto x = nums[i%len];

            while (que.size() && (que.back().first-i+1 > len || x >= que.back().second)) {
                que.pop_back();
            }

            if (que.size() && i <= len-1) {
                ans[i] = que.back().second;
            } else if (i <= len-1) {
                ans[i] = -1;
            }

            que.push_back({i, x});
        }

        return ans;
    }
};
