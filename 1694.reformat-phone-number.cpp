// CreateTime: 2020-12-20 10:31:20
class Solution {
public:
    string reformatNumber(string number) {
        vector<string> arr;

        string sub = "";
        for (int i = 0; i < number.size(); i++) {
            auto x = number[i];
            if ('0' <= x && x <= '9') {
                sub.push_back(x);
            }

            if (sub.size() > 0 && (sub.size() == 3 || i == number.size()-1)) {
                arr.push_back(sub);
                sub = "";
            }
        }

        if (arr.size() >= 2 && arr.back().size() == 1) {
            auto last1 = arr.back();
            arr.pop_back();
            auto last2 = arr.back();
            arr.pop_back();

            auto x = last2.back();
            last2.pop_back();

            last1.insert(last1.begin(), x);

            arr.push_back(last2);
            arr.push_back(last1);
        }

        string ans;
        for (int i = 0; i < arr.size(); i++) {
            if (i == arr.size()-1) {
                ans += (arr[i]);
            } else {
                ans += (arr[i] + "-");
            }
        }
        return ans;
    }
};