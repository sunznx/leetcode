class NumArray {
public:
    vector<int> data;
    vector<int> root;

    NumArray(vector<int> nums) {
        data = nums;
        for (int i = 0; i < 3 * nums.size(); i++) {
            root.push_back(0);
        }

        build(0, 0, data.size()-1);
    }

    int left(int idx) {
        return 2 * idx + 1;
    }

    int right(int idx) {
        return 2 * idx + 2;
    }

    void build(int idx, int l, int r) {
        if (l > r) {
            return;
        }

        if (l == r) {
            root[idx] = data[l];
            return;
        }

        int mid = (l+r) / 2;
        build(left(idx), l, mid);
        build(right(idx), mid+1, r);
        root[idx] = root[left(idx)] + root[right(idx)];
    }

    void update(int i, int val) {
        data[i] = val;
        build(0, 0, data.size()-1);
    }

    int sumRange(int i, int j) {
        return sumRange(i, j, 0, 0, data.size()-1);
    }

    int sumRange(int i, int j, int idx, int L, int R) {
        if (i <= L && R <= j) {
            return root[idx];
        }

        if (i > R || j < L) {
            return 0;
        }

        int mid = (L+R) / 2;
        return sumRange(i, j, left(idx), L, mid) +
            sumRange(i, j, right(idx), mid+1, R);
    }
};
