class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> res;
        for (int i = 1; i <= n; i++) {
            int num1 = i % 3;
            int num2 = i % 5;
            string str;
            if (num1 == 0 && num2 == 0) {
                str = "FizzBuzz";
            } else if (num1 == 0) {
                str = "Fizz";
            } else if (num2 == 0) {
                str = "Buzz";
            } else {
                int num = i;
                while (num) {
                    int mod = num % 10;
                    num = num / 10;
                    str.insert(0, 1, mod+'0');
                }
            }
            
            res.push_back(str);
        }
        return res;
    }
};
