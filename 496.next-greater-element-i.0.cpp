// CreateTime: 2020-11-22 01:12:29
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> m;
        vector<int> aux(nums2.size(), -1);
        stack<int> s;

        for (int i = nums2.size()-1; i >= 0; i--) {
            auto num = nums2[i];

            while (s.size() && s.top() <= num) {
                s.pop();
            }

            if (s.size() && num < s.top()) {
                aux[i] = s.top();
            } else {
                aux[i] = -1;
            }

            s.push(num);

            m[num] = i;
        }

        vector<int> ans(nums1.size(), -1);
        for (int i = 0; i < nums1.size(); i++) {
            auto k = m[nums1[i]];
            ans[i] = aux[k];
        }

        return ans;
    }
};
