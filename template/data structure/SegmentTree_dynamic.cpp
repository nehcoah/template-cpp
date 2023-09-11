//
// Created by Nehcoah on 2023/5/3.
//

#include <vector>

using namespace std;

template<typename T>
struct Node {
    Node *left;
    Node *right;
    T sum, lazy;
    Node(): left(nullptr), right(nullptr), lazy(T()), sum(T()) {}
};

template<typename T>
struct SegmentTree {
private:
    Node<T> *root;
    long long n;

    void init(long long sz) {
        this->n = sz;
        root = new Node<T>();
    }

    void build_(vector<T> &nums, Node<T> *cur, long long l, long long r) {
        if (l == r) {
            cur->sum = nums[l];
            return;
        }
        if (cur->left == nullptr) cur->left = new Node<T>();
        if (cur->right == nullptr) cur->right = new Node<T>();
        long long mid = (l + r) >> 1;
        build_(nums, cur->left, l, mid);
        build_(nums, cur->right, mid + 1, r);
        cur->sum = cur->left->sum + cur->right->sum;
    }

    void push_down(Node<T> *cur, long long len){
        if (cur->left == nullptr) cur->left = new Node<T>();
        if (cur->right == nullptr) cur->right = new Node<T>();
        if (cur->lazy) {
            cur->left->sum += cur->lazy * (len - len / 2);
            cur->right->sum += cur->lazy * len / 2;
            cur->left->lazy += cur->lazy;
            cur->right->lazy += cur->lazy;
            cur->lazy = T();
        }
    }

    void update_(Node<T> *cur, long long l, long long r, long long ql, long long qr, T val) {
        if (ql <= l && r <= qr) {
            cur->lazy += val;
            cur->sum += val * (r - l + 1);
            return;
        }
        push_down(cur, r - l + 1);
        long long mid = (l + r) >> 1;
        if (ql <= mid) update_(cur->left, l, mid, ql, qr, val);
        if (mid < qr) update_(cur->right, mid + 1, r, ql, qr, val);
        cur->sum = cur->left->sum + cur->right->sum;
    }

    T query_sum_(Node<T> *cur, long long l, long long r, long long ql, long long qr) {
        if (ql <= l && r <= qr) {
            return cur->sum;
        }
        push_down(cur, r - l + 1);
        long long mid = (l + r) >> 1;
        auto sum = T();
        if (ql <= mid) sum += query_sum_(cur->left, l, mid, ql, qr);
        if (mid < qr) sum += query_sum_(cur->right, mid + 1, r, ql, qr);
        return sum;
    }

public:
    SegmentTree(long long n = 1e9 + 1) {
        init(n);
    }

    void build(vector<T> &nums) {
        build_(nums, root, 0, n - 1);
    }

    void update_single(long long index, T val) {
        update_(root, 0, n - 1, index, index, val);
    }

    void update_interval(long long ql, long long qr, T val) {
        update_(root, 0, n - 1, ql, qr, val);
    }

    T query_sum(long long ql, long long qr) {
        return query_sum_(root, 0, n - 1, ql, qr);
    }
};
