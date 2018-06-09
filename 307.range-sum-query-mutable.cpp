class NumArray {
public:
    vector<int> data;
    vector<int> tree;
    vector<int> lazy;

    NumArray(vector<int> nums) {
        for (int i = 0; i < nums.size(); i++) {
            data.push_back(nums[i]);
        }
        for (int i = 0; i <= 3*data.size(); i++) {
            tree.push_back(0);
        }
        for (int i = 0; i <= 3*data.size(); i++) {
            lazy.push_back(0);
        }

        build(0, 0, nums.size()-1);
    }

    int left(int x) {
        return 2*x + 1;
    }

    int right(int x) {
        return 2*x + 2;
    }

    int mid(int l, int r) {
        return (l+r)/2;
    }

    void build(int root, int l, int r) {
        if (l > r) {
            return;
        }

        if (l == r) {
            tree[root] = data[l];
            return;
        }

        build(left(root), l, mid(l,r));
        build(right(root), mid(l,r)+1, r);
        tree[root] = tree[left(root)] + tree[right(root)];
    }

    void update(int i, int val) {
        int diff = val - data[i];
        data[i] = val;
        updateInterval(i, diff, 0, 0, data.size()-1);
    }

    void updateInterval(int index, int diff, int root, int l, int r) {
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
            tree[root] += diff;

            if (l != r) {
                lazy[left(root)]  = diff;
                lazy[right(root)] = diff;
            }

            return;
        }

        /* 一部分包含 */
        int m = mid(l, r);

        updateInterval(index, diff, left(root),  l,   m);
        updateInterval(index, diff, right(root), m+1, r);

        tree[root] = tree[left(root)] + tree[right(root)];
    }

    int sumRange(int i, int j) {
        return sumRange(i, j, 0, 0, data.size()-1);
    }

    int sumRange(int query_min, int query_max, int root, int l, int r) {
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

        int lsum = sumRange(query_min, query_max, left(root),  l,   m);
        int rsum = sumRange(query_min, query_max, right(root), m+1, r);

        return lsum + rsum;
    }
};
