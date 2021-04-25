// CreateTime: 2021-04-11 10:20:49
class MKAverage {
public:

    typedef long long LL;

    int m;
    int k;

    class Range {
    public:
        multiset<int> S;
        LL sum = 0;

        void insert(int num) {
            S.insert(num);
            sum += num;
        }

        void remove(int num) {
            S.erase(S.find(num));
            sum -= num;
        }

        int size() {
            return S.size();
        }

        bool exist(int x) {
            return S.find(x) != S.end();
        }
    };

    Range L;
    Range M;
    Range R;
    vector<int> nums;

    MKAverage(int m, int k) {
        this->m = m;
        this->k = k;
    }

    void addElement(int num) {
        nums.push_back(num);

        if (nums.size() < m) {
            return;
        } else if (nums.size() == m) {
            auto SA = nums;
            sort(SA.begin(), SA.end());
            for (int i = 0; i < k; i++) {
                L.insert(SA[i]);
            }
            for (int i = k; i < m-k; i++) {
                M.insert(SA[i]);
            }
            for (int i = m-k; i < m; i++) {
                R.insert(SA[i]);
            }
        } else {
            M.insert(num);

            auto l = *L.S.rbegin();
            auto ml = *M.S.begin();
            auto mr = *M.S.rbegin();
            auto r = *R.S.begin();

            if (l > ml) {
                M.remove(ml);
                M.insert(l);
                L.remove(l);
                L.insert(ml);
            }
            if (r < mr) {
                M.remove(mr);
                M.insert(r);
                R.remove(r);
                R.insert(mr);
            }

            auto x = nums[nums.size()-1-m];
            if (M.exist(x)) {
                M.remove(x);
            } else if (L.exist(x)) {
                L.remove(x);
                auto y = *M.S.begin();
                M.remove(y);
                L.insert(y);
            } else if (R.exist(x)) {
                R.remove(x);
                auto y = *M.S.rbegin();
                M.remove(y);
                R.insert(y);
            }
        }
    }

    int calculateMKAverage() {
        if (nums.size() < m) {
            return -1;
        }
        return M.sum / M.size();
    }
};

/**
 * Your MKAverage object will be instantiated and called as such:
 * MKAverage* obj = new MKAverage(m, k);
 * obj->addElement(num);
 * int param_2 = obj->calculateMKAverage();
 */