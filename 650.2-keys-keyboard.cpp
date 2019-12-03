class Solution {
public:
    int minSteps(int n) {
        if (n == 1) {
            return 0;
        }

        return f(n, 0, 1, 0);
    }

    int f(int n, int count, int copy, int res) {
        if (n == count) {
            return res;
        }

        if (count > n) {
            return n;
        }

        int res1 = f(n, count + copy, copy, res + 1);         // paste
        int res2 = f(n, count + copy, count + copy, res + 2); // paste + copy

        return min(res1, res2);
    }
};


// https://leetcode.com/problems/2-keys-keyboard/discuss/105928/javac-clean-code-with-explanation-4-lines-no-dp/108405?page=1
// class Solution {
// public:
//     int minSteps(int n) {
//         if (n == 1) {
//             return 0;
//         }

//         for (int i = 2; i < n; i++) {
//             if (n % i == 0) {
//                 return i + minSteps(n/i);
//             }
//         }

//         return n;
//     }
// };
