//
// Created by Nehcoah on 2023/9/12.
//

#include <vector>
#include <iostream>

using namespace std;

struct SegmentTree {
private:
    int n = 0;
    vector<int> val;
    vector<bool> lazy;

    void init(int sz) {
        this->n = sz;
        val.assign(n * 4, 0);
        lazy.assign(n * 4, false);
    }

    void build_from_vector_(vector<int> &a, int tree_index, int l, int r) {
        if (l == r) {
            val[tree_index] = a[l];
            return;
        }
        int mid = (l + r) >> 1;
        build_from_vector_(a, tree_index * 2 + 1, l, mid);
        build_from_vector_(a, tree_index * 2 + 2, mid + 1, r);
        val[tree_index] = val[tree_index * 2 + 1] + val[tree_index * 2 + 2];
    }

    void build_from_string_(string &s, int tree_index, int l, int r) {
        if (l == r) {
            val[tree_index] = s[l] - '0';
            return;
        }
        int mid = (l + r) >> 1;
        build_from_string_(s, tree_index * 2 + 1, l, mid);
        build_from_string_(s, tree_index * 2 + 2, mid + 1, r);
        val[tree_index] = val[tree_index * 2 + 1] + val[tree_index * 2 + 2];
    }

    void push_down(int tree_index, int l, int r) {
        int mid = (l + r) >> 1;
        if (lazy[tree_index]){
            val[tree_index * 2 + 1] = mid - l + 1 - val[tree_index * 2 + 1];
            lazy[tree_index * 2 + 1] = !lazy[tree_index * 2 + 1];

            val[tree_index * 2 + 2] = r - mid - val[tree_index * 2 + 2];
            lazy[tree_index * 2 + 2] = !lazy[tree_index * 2 + 2];

            lazy[tree_index] = false;
        }
    }

    void flip_(int tree_index, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr){
            val[tree_index] = r - l + 1 - val[tree_index];
            lazy[tree_index] = !lazy[tree_index];
            return;
        }
        push_down(tree_index, l, r);
        int mid = (l + r) >> 1;
        if (ql <= mid) flip_(tree_index * 2 + 1, l, mid, ql, qr);
        if (mid < qr) flip_(tree_index * 2 + 2, mid + 1, r, ql, qr);
        val[tree_index] = val[tree_index * 2 + 1] + val[tree_index * 2 + 2];
    }

    int query_sum_(int tree_index, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) {
            return val[tree_index];
        }
        push_down(tree_index, l, r);
        int sum_ = 0;
        int mid = (l + r) >> 1;
        if (ql <= mid) sum_ += query_sum_(tree_index * 2 + 1, l, mid, ql, qr);
        if (mid < qr) sum_ += query_sum_(tree_index * 2 + 2, mid + 1, r, ql, qr);
        return sum_;
    }

public:
    explicit SegmentTree(int n = 1e5 + 1) {
        init(n);
    }

    explicit SegmentTree(vector<int> &nums) {
        init(int(nums.size()));
        build_from_vector_(nums, 0, 0, n - 1);
    }

    explicit SegmentTree(string &s) {
        init(int(s.size()));
        build_from_string_(s, 0, 0, n - 1);
    }

    void flip(int index) {
        flip_(0, 0, n - 1, index, index);
    }

    void flip(int ql, int qr) {
        flip_(0, 0, n - 1, ql, qr);
    }

    int query_sum(int ql, int qr) {
        return query_sum_(0, 0, n - 1, ql, qr);
    }

    int count_one(int ql, int qr) {
        return query_sum_(0, 0, n - 1, ql, qr);
    }

    int count_zero(int ql, int qr) {
        return qr - ql + 1 - count_one(ql, qr);
    }

    int check(int index) {
        return query_sum_(0, 0, n - 1, index, index);
    }
};