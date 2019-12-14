// CreateTime: 2019-12-14 15:48:49
class Solution {
public:
    int numberOfDays(int Y, int M) {
        int months[] = {
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
        
        if (M == 2) {
            return isLeapYear(Y) + months[M];
        }
        return months[M];
    }
    
    inline int isLeapYear(int year) {
        return year % 4 == 0 && !(year % 100 == 0 && year % 400 != 0);
    }
};
