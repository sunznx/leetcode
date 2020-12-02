// CreateTime: 2020-12-02 10:27:50
class Solution
{
public:
    vector<int> maxNumber(vector<int> &nums1, vector<int> &nums2, int k)
    {
        vector<int> ans(k, -1);
        vector<int> m(k, -1);

        for (int i = 0; i <= k; i++) {
            auto l1 = i;
            auto l2 = k - i;
            if (nums1.size() >= l1 && nums2.size() >= l2) {
                auto max1 = maxK(nums1, l1);
                auto max2 = maxK(nums2, l2);
                merge(max1, max2, m);
                ans = max(ans, m);
            }
        }
        return ans;
    }

    void merge(vector<int> &nums1, vector<int> &nums2, vector<int> &m)
    {
        int k = 0;
        while (nums1.size() != 0 || nums2.size() != 0) {
            if (nums1 > nums2) {
                m[k++] = nums1[0];
                nums1.erase(nums1.begin());
            } else {
                m[k++] = nums2[0];
                nums2.erase(nums2.begin());
            }
        }
    }

    vector<int> maxK(vector<int> &nums, int k)
    {
        int len = nums.size();

        int maxRemove = len - k;
        int removed = 0;

        deque<int> q;

        for (int i = 0; i < len; i++) {
            while (removed < maxRemove && q.size() && nums[i] > q.back()) {
                removed++;
                q.pop_back();
            }
            q.push_back(nums[i]);
        }

        vector<int> ans(k);
        for (int i = 0; i < k; i++) {
            ans[i] = q.front();
            q.pop_front();
        }
        return ans;
    }
};