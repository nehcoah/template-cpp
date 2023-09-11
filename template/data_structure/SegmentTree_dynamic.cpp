//
// Created by Nehcoah on 2023/5/3.
//

#include <vector>

using namespace std;

template<typename T>
struct Node {
    Node *left, *right;
    T val, mx, mn, lazy_add, lazy_mul, lazy_modify;
    Node(T setup_mx, T setup_mn) {
        left = right = nullptr;
        val = T();
        mx = setup_mx;
        mn = setup_mn;
        lazy_add = lazy_modify = T();
        lazy_mul = T(1);
    }
};

template<typename T>
struct SegmentTree {
private:
    Node<T> *root;
    long long n;
    T setup_mx, setup_mn;

    void init(long long sz, T mx = T(), T mn = T()) {
        this->n = sz;
        setup_mx = mx;
        setup_mn = mn;
        root = new Node<T>(setup_mx, setup_mn);
    }

    void build_(vector<T> &nums, Node<T> *cur, long long l, long long r) {
        if (l == r) {
            cur->val = nums[l];
            cur->mx = nums[l];
            cur->mn = nums[l];
            return;
        }
        if (cur->left == nullptr) cur->left = new Node<T>(setup_mx, setup_mn);
        if (cur->right == nullptr) cur->right = new Node<T>(setup_mx, setup_mn);
        long long mid = (l + r) >> 1;
        build_(nums, cur->left, l, mid);
        build_(nums, cur->right, mid + 1, r);
        cur->val = cur->left->val + cur->right->val;
        cur->mx = max(cur->left->mx, cur->right->mx);
        cur->mn = min(cur->left->mn, cur->right->mn);
    }

    void push_down(Node<T> *cur, long long l, long long r){
        if (cur->left == nullptr) cur->left = new Node<T>(setup_mx, setup_mn);
        if (cur->right == nullptr) cur->right = new Node<T>(setup_mx, setup_mn);

        long long mid = (l + r) >> 1;
        // priority: modify > mul > add
        if (cur->lazy_modify) {
            cur->left->val = cur->lazy_modify * (mid - l + 1);
            cur->right->val = cur->lazy_modify * (r - mid);

            cur->left->mx = cur->right->mx = cur->lazy_modify;
            cur->left->mn = cur->right->mn = cur->lazy_modify;

            cur->left->lazy_modify = cur->right->lazy_modify = cur->lazy_modify;

            cur->left->lazy_add = cur->right->lazy_add = T();
            cur->left->lazy_mul = cur->right->lazy_mul = T(1);

            cur->lazy_modify = T();
        }

        cur->left->val = cur->left->val * cur->lazy_mul + cur->lazy_add * (mid - l + 1);
        cur->right->val = cur->right->val * cur->lazy_mul + cur->lazy_add * (r - mid);

        cur->left->mx = cur->left->mx * cur->lazy_mul + cur->lazy_add;
        cur->right->mx = cur->right->mx * cur->lazy_mul + cur->lazy_add;

        cur->left->mn = cur->left->mn * cur->lazy_mul + cur->lazy_add;
        cur->right->mn = cur->right->mn * cur->lazy_mul + cur->lazy_add;

        cur->left->lazy_mul *= cur->lazy_mul;
        cur->right->lazy_mul *= cur->lazy_mul;
        cur->left->lazy_add = cur->left->lazy_add * cur->lazy_mul + cur->lazy_add;
        cur->right->lazy_add = cur->right->lazy_add * cur->lazy_mul + cur->lazy_add;

        cur->lazy_mul = T(1);
        cur->lazy_add = T();
    }

    void modify_(Node<T> *cur, long long l, long long r, long long ql, long long qr, T k) {
        if (ql <= l && r <= qr) {
            cur->val = k * (r - l + 1);
            cur->mx = k;
            cur->mn = k;
            cur->lazy_modify = k;
            cur->lazy_add = T();
            cur->lazy_mul = T(1);
            return;
        }
        push_down(cur, l, r);
        long long mid = (l + r) >> 1;
        if (ql <= mid) modify_(cur->left, l, mid, ql, qr, k);
        if (mid < qr) modify_(cur->right, mid + 1, r, ql, qr, k);
        cur->val = cur->left->val + cur->right->val;
        cur->mx = max(cur->left->mx, cur->right->mx);
        cur->mn = min(cur->left->mn, cur->right->mn);
    }

    void mul_(Node<T> *cur, long long l, long long r, long long ql, long long qr, T k) {
        if (ql <= l && r <= qr) {
            cur->val *= k;
            cur->mx *= k;
            cur->mn *= k;
            cur->lazy_mul *= k;
            cur->lazy_add *= k;
            return;
        }
        push_down(cur, l, r);
        long long mid = (l + r) >> 1;
        if (ql <= mid) mul_(cur->left, l, mid, ql, qr, k);
        if (mid < qr) mul_(cur->right, mid + 1, r, ql, qr, k);
        cur->val = cur->left->val + cur->right->val;
        cur->mx = max(cur->left->mx, cur->right->mx);
        cur->mn = min(cur->left->mn, cur->right->mn);
    }

    void add_(Node<T> *cur, long long l, long long r, long long ql, long long qr, T k) {
        if (ql <= l && r <= qr) {
            cur->lazy_add += k;
            cur->mx += k;
            cur->mn += k;
            cur->val += k * (r - l + 1);
            return;
        }
        push_down(cur, l, r);
        long long mid = (l + r) >> 1;
        if (ql <= mid) add_(cur->left, l, mid, ql, qr, k);
        if (mid < qr) add_(cur->right, mid + 1, r, ql, qr, k);
        cur->val = cur->left->val + cur->right->val;
        cur->mx = max(cur->left->mx, cur->right->mx);
        cur->mn = min(cur->left->mn, cur->right->mn);
    }

    T query_sum_(Node<T> *cur, long long l, long long r, long long ql, long long qr) {
        if (ql <= l && r <= qr) {
            return cur->val;
        }
        push_down(cur, l, r);
        long long mid = (l + r) >> 1;
        auto sum = T();
        if (ql <= mid) sum += query_sum_(cur->left, l, mid, ql, qr);
        if (mid < qr) sum += query_sum_(cur->right, mid + 1, r, ql, qr);
        return sum;
    }

    T query_mx_(Node<T> *cur, long long l, long long r, long long ql, long long qr) {
        if (ql <= l && r <= qr) {
            return cur->mx;
        }
        push_down(cur, l, r);
        long long mid = (l + r) >> 1;
        auto ans = setup_mx;
        if (ql <= mid) ans = max(ans, query_mx_(cur->left, l, mid, ql, qr));
        if (mid < qr) ans = max(ans, query_mx_(cur->right, mid + 1, r, ql, qr));
        return ans;
    }

    T query_mn_(Node<T> *cur, long long l, long long r, long long ql, long long qr) {
        if (ql <= l && r <= qr) {
            return cur->mn;
        }
        push_down(cur, l, r);
        long long mid = (l + r) >> 1;
        auto ans = setup_mn;
        if (mid < qr) ans = min(ans, query_mn_(cur->right, mid + 1, r, ql, qr));
        if (ql <= mid) ans = min(ans, query_mn_(cur->left, l, mid, ql, qr));
        return ans;
    }

public:
    SegmentTree(long long n = 1e9 + 1, T setup_mx = T(), T setup_mn = T()) {
        init(n, setup_mx, setup_mn);
    }

    void build(vector<T> &nums) {
        build_(nums, root, 0, n - 1);
    }

    void modify(long long index, T val) {
        modify_(root, 0, n - 1, index, index, val);
    }

    void modify(long long ql, long long qr, T val) {
        modify_(root, 0, n - 1, ql, qr, val);
    }

    void mul(long long index, T val) {
        mul_(root, 0, n - 1, index, index, val);
    }

    void mul(long long ql, long long qr, T val) {
        mul_(root, 0, n - 1, ql, qr, val);
    }

    void add(long long index, T val) {
        add_(root, 0, n - 1, index, index, val);
    }

    void add(long long ql, long long qr, T val) {
        add_(root, 0, n - 1, ql, qr, val);
    }

    T query_sum(long long ql, long long qr) {
        return query_sum_(root, 0, n - 1, ql, qr);
    }

    T query_mx(long long ql, long long qr) {
        return query_mx_(root, 0, n - 1, ql, qr);
    }

    T query_mn(long long ql, long long qr) {
        return query_mn_(root, 0, n - 1, ql, qr);
    }
};