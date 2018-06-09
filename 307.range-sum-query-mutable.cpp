class NumArray {
public:
    vector<int> data;
    vector<int> tree;
    vector<int> lazy;

    NumArray(vector<int> nums) {
        for (int i = 0; i < nums.size(); i++) {
            data.push_back(nums[i]);
        }
        for (int i = 0; i <= 2*data.size()+2; i++) {
            tree.push_back(0);
        }
        for (int i = 0; i <= 2*data.size()+2; i++) {
            lazy.push_back(0);
        }

        build(0, 0, nums.size()-1);
    }

    void update(int i, int val) {
        data[i] = val;
        build(0, 0, data.size()-1);
    }

    int sumRange(int i, int j) {
        return sumRange(i, j, 0, 0, data.size()-1);
    }

    int sumRange(int i, int j, int root, int L, int R) {
        if (i <= L && j >= R) {
            return tree[root];
        }
        if (i > R || j < L) {
            return 0;
        }

        return sumRange(i, j, left(root), L, mid(L, R))
            + sumRange(i, j, right(root), mid(L, R)+1, R);
    }

    void build(int root, int l, int r) {
        if (l == r) {
            tree[root] = data[l];
            return;
        }

        if (l > r) {
            return;
        }

        build(left(root), l, mid(l, r));
        build(right(root), mid(l, r)+1, r);
        tree[root] = tree[left(root)] + tree[right(root)];
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
};
