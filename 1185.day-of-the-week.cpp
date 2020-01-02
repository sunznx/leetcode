// CreateTime: 2020-01-02 10:05:05
class Solution {
public:
    string dayOfTheWeek(int day, int month, int year) {
        vector<string> weeks = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
        vector<vector<int>> months = {
            {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
            {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
        };

        // 1970-01-01
        int res = 4;

        for (int y = 1970; y < year; y++) {
            for (int m = 1; m <= 12; m++) {
                for (int d = 1; d <= months[isLeapYear(y)][m]; d++) {
                    res = (res + 1) % 7;
                }
            }
        }

        for (int m = 1; m < month; m++) {
            for (int d = 1; d <= months[isLeapYear(year)][m]; d++) {
                res = (res + 1) % 7;
            }
        }

        for (int d = 1; d < day; d++) {
            res = (res + 1) % 7;
        }

        return weeks[res];
    }

    bool isLeapYear(int year) {
        return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
    }
};
