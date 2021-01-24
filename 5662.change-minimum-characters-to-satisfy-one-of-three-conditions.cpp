// CreateTime: 2021-01-24 10:38:37
class Solution {
public:
    int minCharacters(string a, string b) {
        vector<int> arr1(26);
        vector<int> arr2(26);
        for (auto &x: a) {
            arr1[x-'a']++;
        }
        for (auto &x: b) {
            arr2[x-'a']++;
        }
        return min({same(arr1, arr2), big(arr1, arr2), big(arr2, arr1)});
    }

    int same(vector<int> &arr1, vector<int> &arr2) {
        int ans = INT_MAX;
        for (int i = 0; i < 26; i++) {
            int cur = 0;
            for (int j = 0; j < 26; j++) {
                if (j == i) {
                    continue;
                }
                cur += arr1[j] + arr2[j];
            }
            ans = min(ans, cur);
        }

        return ans;
    }

    int big(vector<int> &arr1, vector<int> &arr2) {
        int ans = INT_MAX;
        for (int i = 1; i < 26; i++) {
            int cur = 0;
            for (int j = 0; j <= i-1; j++) {
                cur += arr1[j];
            }
            for (int j = i; j < 26; j++) {
                cur += arr2[j];
            }
            ans = min(ans, cur);
        }
        return ans;
    }
};