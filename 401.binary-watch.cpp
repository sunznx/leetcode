class Solution {
public:
    int value[11] = {0, 1, 2, 4, 8, 16, 32, 1, 2, 4, 8};

    vector<int> data;
    vector<int> v;
    vector<string> res;

    vector<string> readBinaryWatch(int num) {

        for (int i = 0; i <= 10; i++) {
            v.push_back(0);

        }

        for (int i = 0; i < num; i++) {
            data.push_back(0);
        }

        dfs(1, 1, num);
        
        return res;
    }

    void dfs(int step, int index, int n) {
        if (step == n+1) {
            int hour = 0;
            int minute = 0;
            for (int i = 0; i < n; i++) {
                if (1 <= data[i] && data[i] <= 6) {
                    minute += value[data[i]];
                } else if (7 <= data[i] && data[i] <= 10) {
                    hour += value[data[i]];
                }
            }

            if (minute >= 60) {
                return;
            }
            if (hour >= 12) {
                return;
            }

            string str;
            if (minute < 10) {
                str = to_string(hour) + ":0" + to_string(minute);
            } else {
                str = to_string(hour) + ":" + to_string(minute);
            }
            
            res.push_back(str);

            return;
        }

        for (int i = index; i <= 10; i++) {
            data[step-1] = i;
            dfs(step+1, i+1, n);
        }
    }
};
