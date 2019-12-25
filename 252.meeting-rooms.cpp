// CreateTime: 2019-12-25 15:01:42
class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),
             [](auto v1, auto v2) {
                 return v1[0] < v2[0];
             });

        int len = intervals.size();
        for (int i = 1; i < len; i++) {
            if (intervals[i][0] < intervals[i-1][1]) {
                return false;
            }
        }

        return true;
    }
};
