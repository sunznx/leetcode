// CreateTime: 2021-03-20 23:16:06
class Solution {
public:
    vector<vector<int>> g;
    vector<int> f;

    int count(int x) {
        int ans = 0;
        while (x) {
            ans++;
            x = (x & (x-1));
        }
        return ans;
    }

    int maxScore(vector<int>& nums) {
        int len = nums.size();
        g.resize(len, vector<int>(len));
        f.resize(1<<len);

        for (int i = 0; i < (1<<len); i++) {
            int cnt = count(i);
            if (cnt % 2 != 0) {
                continue;
            }

            for (int j = 0; j < len; j++) {
                if ((i & (1<<j)) == 0) {
                    continue;
                }

                for (int k = j+1; k < len; k++) {
                    if ((i & (1<<k)) == 0) {
                        continue;
                    }

                    int s = i - (1<<j) - (1<<k);
                    f[i] = max(f[i], f[s] + (cnt/2)*gcd(nums, j, k));
                }
            }
        }

        return f[(1<<len)-1];
    }

    int gcd(vector<int>& nums, int j, int k) {
        if (g[j][k] == 0) {
            g[j][k] = gcd(nums[j], nums[k]);
        }
        return g[j][k];
    }

    int gcd(int a, int b) {
        if (a < b) {
            return gcd(b, a);
        }

        if (a % b == 0) {
            return b;
        }
        return gcd(b, a % b);
    }
};