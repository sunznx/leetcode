class Solution {
public:
    string multiply(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        int len1 = a.size();
        int len2 = b.size();
        string res = "";
        res.insert(0, len1 + len2, '0');

        vector<int> carry(len1 + len2, 0);
        for (int i = 0; i < len1; i++) {
            for (int j = 0; j < len2; j++) {
                int index = i+j;

                int val;
                int val1 = a[i] - '0';
                int val2 = b[j] - '0';
                int val3 = val3 = res[index] - '0';

                val  = val1 * val2 + val3 + carry[index];
                carry[index] = 0;

                carry[index+1] += val / 10;
                val = val % 10;

                res[index] = val + '0';
            }
        }
        res[len1+len2-1] += carry[len1+len2-1];

        reverse(res.begin(), res.end());
        while ((*(res.begin())) == '0' && res.size() > 1) {
            res.erase(res.begin());
        }

        return res;
    }
};
