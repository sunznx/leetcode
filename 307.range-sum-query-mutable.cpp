class NumArray {
public:
    vector<int> data;
    vector<int> tree;
    vector<int> lazy;
    int n;

    NumArray(vector<int> nums) {
        n = nums.size();
        data = nums;
        for (int i = 0; i < n; i++) {
            data.push_back(0);
        }
        for (int i = 0; i < 3*n; i++) {
            tree.push_back(0);
        }
        for (int i = 0; i < 3*n; i++) {
            lazy.push_back(0);
        }

        buildWrap(0, 0, n-1);
    }

    int left(int x) {
        return x * 2 + 1;
    }

    int right(int x) {
        return x * 2 + 2;
    }

    int mid(int l, int r) {
        int m = (l + r) / 2;
        return m;
    }


    void buildWrap(int root, int l, int r) {
        if (l > r) {
            return;
        }

        if (l == r) {
            tree[root] = data[l];
            return;
        }

        int m = mid(l, r);

        buildWrap(left(root), l,    m);
        buildWrap(right(root), m+1, r);

        tree[root] = tree[left(root)] + tree[right(root)];
    }

    void update(int index, int val) {
        int diff = val - data[index];
        data[index] = val;
        updateWrap(index, diff, 0, 0, n-1);
    }

    void updateWrap(int index, int val, int root, int l, int r) {
        if (lazy[root] != 0) {
            tree[root] += lazy[root];

            if (l != r) {
                lazy[left(root)]  += lazy[root];
                lazy[right(root)] += lazy[root];
            }

            lazy[root] = 0;
        }

        /* 完全不包含 */
        if (l > r || l > index || r < index) {
            return;
        }

        /* 全部包含 */
        if (index <= l && r <= index) {
            tree[root] += val;

            if (l != r) {
                lazy[left(root)]  = val;
                lazy[right(root)] = val;
            }

            return;
        }

        /* 一部分包含 */
        int m = mid(l, r);

        updateWrap(index, val, left(root),  l,   m);
        updateWrap(index, val, right(root), m+1, r);

        tree[root] = tree[left(root)] + tree[right(root)];
    }

    int sumRange(int query_min, int query_max) {
        return sumRangeWrap(query_min, query_max, 0, 0, n-1);
    }
    int sumRangeWrap(int query_min, int query_max, int root, int l, int r) {
        if (lazy[root] != 0) {
            tree[root] += lazy[root];

            if (l != r) {
                lazy[left(root)]  += lazy[root];
                lazy[right(root)] += lazy[root];
            }

            lazy[root] = 0;
        }

        if (query_min <= l && r <= query_max) {
            return tree[root];
        }

        if (query_min > r || query_max < l || l > r) {
            return 0;
        }

        int m = mid(l, r);

        int lsum = sumRangeWrap(query_min, query_max, left(root),  l,   m);
        int rsum = sumRangeWrap(query_min, query_max, right(root), m+1, r);

        return lsum + rsum;
    }
};
