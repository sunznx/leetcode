// CreateTime: 2021-04-12 11:13:52
class Solution {
public:
    int ans = 0;

    int longestDecomposition(string text) {
        int l = 0;
        int r = text.size()-1;

        int i = 0;
        int j = text.size()-1;
        int k = 0;
        while (i < j) {
            if (text[i] == text[j]) {
                int sz = i-l+1;

                bool ok = true;
                for (int s = 0; s < sz; s++) {
                    int k1 = l+s;
                    int k2 = r-sz+1+s;

                    if (text[k1] != text[k2]) {
                        ok = false;
                        break;
                    }
                }

                if (ok) {
                    l = l+sz;
                    r = r-sz;
                    i = l;
                    j = r;
                    k += 2 * sz;
                    ans += 2;
                } else {
                    i++;
                }
            } else {
                i++;
            }
        }

        if (k < text.size()) {
            ans += 1;
        }
        return ans;
    }
};