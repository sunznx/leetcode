// CreateTime: 2020-12-02 10:27:50
class Solution
{
public:
    vector<int> maxNumber(vector<int> &nums1, vector<int> &nums2, int k) {
        vector<int> ans(k, -1);
        vector<int> m(k, -1);

        // int start = 0;
        // int end = k;

        int start = max(0, (int)(k - nums2.size()));
        int end = min(k, (int)(nums1.size()));

        for (int i = start; i <= end; i++) {
            auto l1 = i;
            auto l2 = k - i;
            if (nums1.size() >= l1 && nums2.size() >= l2) {
                auto max1 = maxK(nums1, l1);
                auto max2 = maxK(nums2, l2);
                merge(max1, max2, m);
                if (compare(ans, m) < 0) {
                    ans = m;
                }
            }
        }
        return ans;
    }

    void merge(vector<int> &nums1, vector<int> &nums2, vector<int> &m) {
        int k = 0;
        int s1 = 0;
        int s2 = 0;
        while (s1 != nums1.size() || s2 != nums2.size()) {
            if (compare(nums1, nums2, s1, s2) > 0) {
                m[k++] = nums1[s1++];
            } else {
                m[k++] = nums2[s2++];
            }
        }
    }

    vector<int> maxK(vector<int> &nums, int k) {
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

    int compare(vector<int>& nums1, vector<int>& nums2, int s1 = 0, int s2 = 0) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        while (s1 < len1 && s2 < len2) {
            int diff = nums1[s1] - nums2[s2];
            if (diff != 0) {
                return diff;
            }
            s1++;
            s2++;
        }

        if (s2 == len2) {
            return 1;
        }
        if (s1 == len1) {
            return -1;
        }
        return 0;
    }
};