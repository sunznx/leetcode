class Solution {
public:
    void swap(string &str, int i, int j) {
        char c = str[i];
        str[i] = str[j];
        str[j] = c;
    }

    int partition(string &str, int l, int r) {
        char x = str[r];
        int k = l-1;

        for (int i = l; i < r; i++) {
            if (str[i] < x) {
                swap(str, k+1, i);
                k = k + 1;
            }
        }
        swap(str, k+1, r);

        return k+1;
    }

    void sort(string &str, int l, int r) {
        if (l >= r) {
            return;
        }

        int p = partition(str, l, r);
        sort(str, l, p-1);
        sort(str, p+1, r);
    }

    void sort(string &str) {
        int len = str.size();
        sort(str, 0, len-1);
    }

    bool isAnagram(string s, string t) {
        int len1 = s.size();
        int len2 = t.size();
        
        if (len1 != len2) {
            return false;
        }
        
        sort(s);
        sort(t);

        for (int i = 0; i < len1; i++) {
            if (s[i] != t[i]) {
                return false;
            }
        }
        
        return true;
    }
};
