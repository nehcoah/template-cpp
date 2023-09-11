//
// Created by Nehcoah on 2023/5/3.
//

#include <vector>

using namespace std;

template<typename T>
struct SegmentTree {
private:
    vector<T> sum, mn, lazy;
    int n;

    void init(int sz) {
        this->n = sz;
        sum.assign(n * 4, T());
        mn.assign(n * 4, T());
        lazy.assign(n * 4, T());
    }

    void build_(vector<T> &nums, int tree_index, int l, int r) {
        if (l == r) {
            sum[tree_index] = nums[l];
            mn[tree_index] = nums[l];
            return;
        }
        int mid = (l + r) >> 1;
        build_(nums, tree_index * 2 + 1, l, mid);
        build_(nums, tree_index * 2 + 2, mid + 1, r);
        sum[tree_index] = sum[tree_index * 2 + 1] + sum[tree_index * 2 + 2];
        mn[tree_index] = min(mn[tree_index * 2 + 1], mn[tree_index * 2 + 2]);
    }

    void push_down(int tree_index, int l, int r) {
        if (lazy[tree_index]) {
            int mid = (l + r) >> 1;
            sum[tree_index * 2 + 1] += lazy[tree_index] * (mid - l + 1);
            mn[tree_index * 2 + 1] += lazy[tree_index];
            lazy[tree_index * 2 + 1] += lazy[tree_index];

            sum[tree_index * 2 + 2] += lazy[tree_index] * (r - mid);
            mn[tree_index * 2 + 2] += lazy[tree_index];
            lazy[tree_index * 2 + 2] += lazy[tree_index];

            lazy[tree_index] = T();
        }
    }

    void update_single_(int tree_index, int l, int r, int index, T val) {
        if (l == r) {
            sum[tree_index] += val;
            mn[tree_index] += val;
            return;
        }
        push_down(tree_index, l, r);

        int mid = (l + r) >> 1;
        if (index <= mid) update_single_(tree_index * 2 + 1, l, mid, index, val);
        else update_single_(tree_index * 2 + 2, mid + 1, r, index, val);
        sum[tree_index] = sum[tree_index * 2 + 1] + sum[tree_index * 2 + 2];
        mn[tree_index] = min(mn[tree_index * 2 + 1], mn[tree_index * 2 + 2]);
    }

    void update_interval_(int tree_index, int l, int r, int ql, int qr, T val) {
        if (ql <= l && r <= qr){
            sum[tree_index] += (r - l + 1) * val;
            mn[tree_index] += val;
            lazy[tree_index] += val;
            return;
        }
        push_down(tree_index, l, r);

        int mid = (l + r) >> 1;
        if (ql <= mid) update_interval_(tree_index * 2 + 1, l, mid, ql, qr, val);
        if (mid < qr) update_interval_(tree_index * 2 + 2, mid + 1, r, ql, qr, val);
        sum[tree_index] = sum[tree_index * 2 + 1] + sum[tree_index * 2 + 2];
        mn[tree_index] = min(mn[tree_index * 2 + 1], mn[tree_index * 2 + 2]);
    }

    T query_sum_(int tree_index, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) {
            return sum[tree_index];
        }
        push_down(tree_index, l, r);
        auto sum_ = T();
        int mid = (l + r) >> 1;
        if (ql <= mid) sum_ += query_sum_(tree_index * 2 + 1, l, mid, ql, qr);
        if (qr > mid) sum_ += query_sum_(tree_index * 2 + 2, mid + 1, r, ql, qr);
        return sum_;
    }

    int min_index_(int tree_index, int l, int r, int ql, int qr, T val){
        if (mn[tree_index] > val) return -1;
        if (l == r) return l;
        push_down(tree_index, l, r);
        int mid = (l + r) >> 1;
        if (ql <= mid && mn[tree_index * 2 + 1] <= val) return min_index_(tree_index * 2 + 1, l, mid, ql, qr, val);
        if (mid < qr) return min_index_(tree_index * 2 + 2, mid + 1, r, ql, qr, val);
        return -1;
    }

public:
    SegmentTree(int n = 1e7 + 1) {
        init(n);
    }

    void build(vector<T> &nums) {
        build_(nums, 0, 0, n - 1);
    }

    void update_single(int index, T val) {
        update_single_(0, 0, n - 1, index, val);
    }

    void update_interval(int ql, int qr, T val) {
        update_interval_(0, 0, n - 1, ql, qr, val);
    }

    T query_sum(int ql, int qr) {
        return query_sum_(0, 0, n - 1, ql, qr);
    }

    // find the index of the first element less equal than val
    int min_index(int ql, int qr, T val){
        return min_index_(0, 0, n - 1, ql, qr, val);
    }
};
