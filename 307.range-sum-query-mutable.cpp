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

        build(0, 0, n-1);
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

    void build(int root, int l, int r) {
        if (l > r) {
            return;
        }

        if (l == r) {
            tree[root] = data[l];
            return;
        }

        int m = mid(l, r);
        build(left(root), l,    m);
        build(right(root), m+1, r);

        tree[root] = tree[left(root)] + tree[right(root)];
    }

    void update(int index, int val) {
        int diff = val - data[index];
        data[index] = val;
        updateInterval(index, index, diff, 0, 0, n-1);
    }

    void updateInterval(int i, int j, int diff, int root, int l, int r) {
        if (lazy[root] != 0) {
            tree[root] += (r-l+1) * lazy[root];
            if (l != r) {
                lazy[left(root)]  += lazy[root];
                lazy[right(root)] += lazy[root];
            }
            lazy[root] = 0;
            return;
        }

        /* 完全不包含 */
        if (l > r || l > j || r < i) {
            return;
        }

        /* 全部包含 */
        if (i <= l && r <= j) {
            tree[root] += (r-l+1) * diff;

            if (l != r) {
                lazy[left(root)]  += diff;
                lazy[right(root)] += diff;
            }

            return;
        }

        /* 一部分包含 */
        int m = mid(l, r);
        updateInterval(i, j, diff, left(root),  l,   m);
        updateInterval(i, j, diff, right(root), m+1, r);
        tree[root] = tree[left(root)] + tree[right(root)];
    }

    int sumRange(int query_min, int query_max) {
        return sumRange(query_min, query_max, 0, 0, n-1);
    }
    int sumRange(int query_min, int query_max, int root, int l, int r) {
        if (lazy[root] != 0) {
            tree[root] += (r-l+1) * lazy[root];

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

        int lsum = sumRange(query_min, query_max, left(root),  l,   m);
        int rsum = sumRange(query_min, query_max, right(root), m+1, r);

        return lsum + rsum;
    }
};
