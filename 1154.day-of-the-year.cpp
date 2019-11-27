// CreateTime: 2019-11-27 16:17:46
class Solution {
public:
    int dayOfYear(string date) {
        int year = (date[0] - '0') * 1000 + (date[1] - '0') * 100 + (date[2] - '0') * 10 + (date[3] - '0');
        int month = (date[5] - '0') * 10 + (date[6] - '0');
        int day = (date[8] - '0') * 10 + (date[9] - '0');

        int months[] = {
            0,
            0,
            31,
            28,
            31,
            30,
            31,
            30,
            31,
            31,
            30,
            31,
            30,
            31,
        };

        for (int i = 1; i <= 12; i++) {
            months[i] = months[i] + months[i-1];
        }

        int ans = months[month] + day;
        if (isLeapYear(year) && month > 2) {
            ans += 1;
        }

        return ans;
    }

    int isLeapYear(int year) {
        return year > 1900 && year % 4 == 0;
    }
};
