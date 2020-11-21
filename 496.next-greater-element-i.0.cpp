// CreateTime: 2020-11-22 01:12:29
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> m;
        stack<int> s;

        for (int i = nums2.size()-1; i >= 0; i--) {
            auto num = nums2[i];

            while (s.size() && s.top() <= num) {
                s.pop();
            }

            if (s.size() && num < s.top()) {
                m[num] = s.top();
            } else {
                m[num] = -1;
            }

            s.push(num);
        }

        vector<int> ans;
        for (int i = 0; i < nums1.size(); i++) {
            ans.push_back(m[nums1[i]]);
        }

        return ans;
    }
};
