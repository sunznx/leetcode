// CreateTime: 2020-12-05 02:08:20
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        deque<int> que;
        unordered_map<int, int> m;

        for (int i = nums2.size()-1; i >= 0; i--) {
            auto x = nums2[i];

            m[x] = -1;
            while (que.size() && x > que.back()) {
                que.pop_back();
            }

            if (que.size()) {
                m[x] = que.back();
            }

            que.push_back(x);
        }

        vector<int> ans(nums1.size(), -1);
        for (int i = 0; i < ans.size(); i++) {
            auto x = nums1[i];
            ans[i] = m[x];
        }
        return ans;
    }
};
