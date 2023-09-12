//
// Created by Nehcoah on 2023/5/3.
//

#include <vector>

using namespace std;

template<typename T>
struct SegmentTree {
private:
    int n;
    T setup_mx, setup_mn;
    vector<T> val, mn, mx, lazy_add, lazy_mul, lazy_modify;

    void init(int sz, T mx_, T mn_) {
        this->n = sz;
        this->setup_mx = mx_;
        this->setup_mn = mn_;
        val.assign(n * 4, T());
        mn.assign(n * 4, setup_mn);
        mx.assign(n * 4, setup_mx);
        lazy_add.assign(n * 4, T());
        lazy_mul.assign(n * 4, T(1));
        lazy_modify.assign(n * 4, T());
    }

    void build_(vector<T> &nums, int tree_index, int l, int r) {
        if (l == r) {
            val[tree_index] = nums[l];
            mn[tree_index] = nums[l];
            mx[tree_index] = nums[l];
            return;
        }
        int mid = (l + r) >> 1;
        build_(nums, tree_index * 2 + 1, l, mid);
        build_(nums, tree_index * 2 + 2, mid + 1, r);
        val[tree_index] = val[tree_index * 2 + 1] + val[tree_index * 2 + 2];
        mn[tree_index] = min(mn[tree_index * 2 + 1], mn[tree_index * 2 + 2]);
        mx[tree_index] = max(mx[tree_index * 2 + 1], mx[tree_index * 2 + 2]);
    }

    void push_down(int tree_index, int l, int r) {
        int mid = (l + r) >> 1;
        // priority: modify > mul > add
        if (lazy_modify[tree_index]) {
            val[tree_index * 2 + 1] = lazy_modify[tree_index] * (mid - l + 1);
            val[tree_index * 2 + 2] = lazy_modify[tree_index] * (r - mid);

            mn[tree_index * 2 + 1] = mn[tree_index * 2 + 2] = lazy_modify[tree_index];
            mx[tree_index * 2 + 1] = mx[tree_index * 2 + 2] = lazy_modify[tree_index];

            lazy_modify[tree_index * 2 + 1] = lazy_modify[tree_index * 2 + 2] = lazy_modify[tree_index];

            lazy_add[tree_index * 2 + 1] = lazy_add[tree_index * 2 + 2] = T();
            lazy_mul[tree_index * 2 + 1] = lazy_mul[tree_index * 2 + 2] = T(1);

            lazy_modify[tree_index] = T();
        }

        val[tree_index * 2 + 1] = val[tree_index * 2 + 1] * lazy_mul[tree_index] + lazy_add[tree_index] * (mid - l + 1);
        val[tree_index * 2 + 2] = val[tree_index * 2 + 2] * lazy_mul[tree_index] + lazy_add[tree_index] * (r - mid);

        mn[tree_index * 2 + 1] = mn[tree_index * 2 + 1] * lazy_mul[tree_index] + lazy_add[tree_index];
        mn[tree_index * 2 + 2] = mn[tree_index * 2 + 2] * lazy_mul[tree_index] + lazy_add[tree_index];

        mx[tree_index * 2 + 1] = mx[tree_index * 2 + 1] * lazy_mul[tree_index] + lazy_add[tree_index];
        mx[tree_index * 2 + 2] = mx[tree_index * 2 + 2] * lazy_mul[tree_index] + lazy_add[tree_index];

        lazy_mul[tree_index * 2 + 1] *= lazy_mul[tree_index];
        lazy_mul[tree_index * 2 + 2] *= lazy_mul[tree_index];
        lazy_add[tree_index * 2 + 1] = lazy_add[tree_index * 2 + 1] * lazy_mul[tree_index] + lazy_add[tree_index];
        lazy_add[tree_index * 2 + 2] = lazy_add[tree_index * 2 + 2] * lazy_mul[tree_index] + lazy_add[tree_index];

        lazy_mul[tree_index] = T(1);
        lazy_add[tree_index] = T();
    }

    void modify_(int tree_index, int l, int r, int ql, int qr, T k) {
        if (ql <= l && r <= qr) {
            val[tree_index] = k * (r - l + 1);
            mx[tree_index] = mn[tree_index] = k;
            lazy_modify[tree_index] = k;
            lazy_add[tree_index] = T();
            lazy_mul[tree_index] = T(1);
            return;
        }
        push_down(tree_index, l, r);
        int mid = (l + r) >> 1;
        if (ql <= mid) modify_(tree_index * 2 + 1, l, mid, ql, qr, k);
        if (mid < qr) modify_(tree_index * 2 + 2, mid + 1, r, ql, qr, k);
        val[tree_index] = val[tree_index * 2 + 1] + val[tree_index * 2 + 2];
        mn[tree_index] = min(mn[tree_index * 2 + 1], mn[tree_index * 2 + 2]);
        mx[tree_index] = max(mx[tree_index * 2 + 1], mx[tree_index * 2 + 2]);
    }

    void mul_(int tree_index, int l, int r, int ql, int qr, T k) {
        if (ql <= l && r <= qr) {
            val[tree_index] *= k;
            mx[tree_index] *= k;
            mn[tree_index] *= k;
            lazy_add[tree_index] *= k;
            lazy_mul[tree_index] *= k;
            return;
        }
        push_down(tree_index, l, r);
        int mid = (l + r) >> 1;
        if (ql <= mid) mul_(tree_index * 2 + 1, l, mid, ql, qr, k);
        if (mid < qr) mul_(tree_index * 2 + 2, mid + 1, r, ql, qr, k);
        val[tree_index] = val[tree_index * 2 + 1] + val[tree_index * 2 + 2];
        mn[tree_index] = min(mn[tree_index * 2 + 1], mn[tree_index * 2 + 2]);
        mx[tree_index] = max(mx[tree_index * 2 + 1], mx[tree_index * 2 + 2]);
    }

    void add_(int tree_index, int l, int r, int ql, int qr, T k) {
        if (ql <= l && r <= qr) {
            val[tree_index] += k * (r - l + 1);
            mx[tree_index] += k;
            mn[tree_index] += k;
            lazy_add[tree_index] += k;
            return;
        }
        push_down(tree_index, l, r);
        int mid = (l + r) >> 1;
        if (ql <= mid) add_(tree_index * 2 + 1, l, mid, ql, qr, k);
        if (mid < qr) add_(tree_index * 2 + 2, mid + 1, r, ql, qr, k);
        val[tree_index] = val[tree_index * 2 + 1] + val[tree_index * 2 + 2];
        mn[tree_index] = min(mn[tree_index * 2 + 1], mn[tree_index * 2 + 2]);
        mx[tree_index] = max(mx[tree_index * 2 + 1], mx[tree_index * 2 + 2]);
    }

    T query_sum_(int tree_index, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) {
            return val[tree_index];
        }
        push_down(tree_index, l, r);
        auto sum_ = T();
        int mid = (l + r) >> 1;
        if (ql <= mid) sum_ += query_sum_(tree_index * 2 + 1, l, mid, ql, qr);
        if (mid < qr) sum_ += query_sum_(tree_index * 2 + 2, mid + 1, r, ql, qr);
        return sum_;
    }

    T query_mx_(int tree_index, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) {
            return mx[tree_index];
        }
        push_down(tree_index, l, r);
        auto ans = setup_mx;
        int mid = (l + r) >> 1;
        if (ql <= mid) ans = max(ans, query_mx_(tree_index * 2 + 1, l, mid, ql, qr));
        if (mid < qr) ans = max(ans, query_mx_(tree_index * 2 + 2, mid + 1, r, ql, qr));
        return ans;
    }

    T query_mn_(int tree_index, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) {
            return mn[tree_index];
        }
        push_down(tree_index, l, r);
        auto ans = setup_mn;
        int mid = (l + r) >> 1;
        if (ql <= mid) ans = min(ans, query_mn_(tree_index * 2 + 1, l, mid, ql, qr));
        if (mid < qr) ans = min(ans, query_mn_(tree_index * 2 + 2, mid + 1, r, ql, qr));
        return ans;
    }

public:
    SegmentTree(int n = 1e7 + 1, T mx_ = T(), T mn_ = T()) {
        init(n, mx_, mn_);
    }

    SegmentTree(vector<T> &nums, T mx_ = T(), T mn_ = T()) {
        init(nums.size(), mx_, mn_);
        build_(nums, 0, 0, n - 1);
    }

    void modify(int index, T k) {
        modify_(0, 0, n - 1, index, index, k);
    }

    void modify(int ql, int qr, T k) {
        modify_(0, 0, n - 1, ql, qr, k);
    }

    void mul(int index, T k) {
        mul_(0, 0, n - 1, index, index, k);
    }

    void mul(int ql, int qr, T k) {
        mul_(0, 0, n - 1, ql, qr, k);
    }

    void add(int index, T k) {
        add_(0, 0, n - 1, index, index, k);
    }

    void add(int ql, int qr, T k) {
        add_(0, 0, n - 1, ql, qr, k);
    }

    T query_sum(int ql, int qr) {
        return query_sum_(0, 0, n - 1, ql, qr);
    }

    T query_mx(int ql, int qr) {
        return query_mx_(0, 0, n - 1, ql, qr);
    }

    T query_mn(int ql, int qr) {
        return query_mn_(0, 0, n - 1, ql, qr);
    }
};