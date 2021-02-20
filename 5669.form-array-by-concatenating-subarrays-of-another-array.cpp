// CreateTime: 2021-02-20 22:47:39
class Solution {
public:
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
        unordered_map<int, deque<int>> m;

        for (int i = 0; i < nums.size(); i++) {
            auto x = nums[i];
            m[x].push_back(i);
        }

        int last = -1;
        for (auto &group: groups) {
            while (true) {
                bool ok = true;
                auto newLast = last;

                for (int i = 0; i < group.size(); i++) {
                    auto x = group[i];

                    while (m[x].size() && m[x].front() < newLast) {
                        m[x].pop_front();
                    }

                    if (m[x].size() == 0) {
                        return false;
                    }

                    if (i == 0) {
                        newLast = m[x].front();
                        m[x].pop_front();
                    } else {
                        if (m[x].front() != newLast+1) {
                            ok = false;
                            break;
                        } else {
                            newLast = m[x].front();
                            m[x].pop_front();
                        }
                    }
                }

                if (ok) {
                    last = newLast;
                    break;
                }
            }
        }
        return true;
    }
};