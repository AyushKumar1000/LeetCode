class NumArray {
public:
    vector<int> seg;
    int n;

    NumArray(vector<int>& nums) {
        n = nums.size();
        seg.resize(4 * n);

        build(nums, 0, 0, n - 1);
    }

    void build(vector<int>& nums, int node, int start, int end) {
        if (start == end) {
            seg[node] = nums[start];
            return;
        }

        int mid = start + (end - start) / 2;

        build(nums, 2 * node + 1, start, mid);
        build(nums, 2 * node + 2, mid + 1, end);

        seg[node] = seg[2 * node + 1] + seg[2 * node + 2];
    }

    void update(int index, int val) {
        updateTree(0, 0, n - 1, index, val);
    }

    void updateTree(int node, int start, int end,
                    int index, int val) {
        if (start == end) {
            seg[node] = val;
            return;
        }

        int mid = start + (end - start) / 2;

        if (index <= mid) {
            updateTree(2 * node + 1, start, mid, index, val);
        } else {
            updateTree(2 * node + 2, mid + 1, end, index, val);
        }

        seg[node] = seg[2 * node + 1] + seg[2 * node + 2];
    }

    int sumRange(int left, int right) {
        return query(0, 0, n - 1, left, right);
    }

    int query(int node, int start, int end,
              int left, int right) {

        if (start > right || end < left) {
            return 0;
        }

        if (start >= left && end <= right) {
            return seg[node];
        }

        int mid = start + (end - start) / 2;

        int leftSum = query(2 * node + 1, start, mid, left, right);
        int rightSum = query(2 * node + 2, mid + 1, end, left, right);

        return leftSum + rightSum;
    }
};