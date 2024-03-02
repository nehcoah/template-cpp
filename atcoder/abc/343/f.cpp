#include "bits/stdc++.h"

using namespace std;
using ll = long long;

template<class Info>
struct SegmentTree {
    int n;
    vector<Info> info;
    SegmentTree() : n(0) {}
    SegmentTree(int n_, Info v_ = Info()) {
        init(n_, v_);
    }
    template<class T>
    SegmentTree(vector<T> init_) {
        init(init_);
    }
    void init(int n_, Info v_ = Info()) {
        init(vector(n_, v_));
    }
    template<class T>
    void init(vector<T> init_) {
        n = init_.size();
        info.assign(4 << int(log2(n)), Info());
        function<void(int, int, int)> build = [&](int p, int l, int r) {
            if (r - l == 1) {
                info[p] = init_[l];
                return;
            }
            int m = (l + r) / 2;
            build(2 * p, l, m);
            build(2 * p + 1, m, r);
            pull(p);
        };
        build(1, 0, n);
    }
    void pull(int p) {
        info[p] = info[2 * p] + info[2 * p + 1];
    }
    void modify(int p, int l, int r, int x, const Info &v) {
        if (r - l == 1) {
            info[p] = v;
            return;
        }
        int m = (l + r) / 2;
        if (x < m) {
            modify(2 * p, l, m, x, v);
        } else {
            modify(2 * p + 1, m, r, x, v);
        }
        pull(p);
    }
    void modify(int p, const Info &v) {
        modify(1, 0, n, p, v);
    }
    Info rangeQuery(int p, int l, int r, int x, int y) {
        if (l >= y || r <= x) {
            return Info();
        }
        if (l >= x && r <= y) {
            return info[p];
        }
        int m = (l + r) / 2;
        return rangeQuery(2 * p, l, m, x, y) + rangeQuery(2 * p + 1, m, r, x, y);
    }
    Info rangeQuery(int l, int r) {
        return rangeQuery(1, 0, n, l, r);
    }
    template<class F>
    int findFirst(int p, int l, int r, int x, int y, F pred) {
        if (l >= y || r <= x || !pred(info[p])) {
            return -1;
        }
        if (r - l == 1) {
            return l;
        }
        int m = (l + r) / 2;
        int res = findFirst(2 * p, l, m, x, y, pred);
        if (res == -1) {
            res = findFirst(2 * p + 1, m, r, x, y, pred);
        }
        return res;
    }
    template<class F>
    int findFirst(int l, int r, F pred) {
        return findFirst(1, 0, n, l, r, pred);
    }
    template<class F>
    int findLast(int p, int l, int r, int x, int y, F pred) {
        if (l >= y || r <= x || !pred(info[p])) {
            return -1;
        }
        if (r - l == 1) {
            return l;
        }
        int m = (l + r) / 2;
        int res = findLast(2 * p + 1, m, r, x, y, pred);
        if (res == -1) {
            res = findLast(2 * p, l, m, x, y, pred);
        }
        return res;
    }
    template<class F>
    int findLast(int l, int r, F pred) {
        return findLast(1, 0, n, l, r, pred);
    }
};

struct Info {
    int top1 = 0, cnt1 = 0, top2 = 0, cnt2 = 0;
};

Info operator+(const Info &a, const Info &b) {
    Info c;
    if (a.top1 > b.top1) {
        c.top1 = a.top1, c.cnt1 = a.cnt1;
        if (a.top2 > b.top1) {
            c.top2 = a.top2, c.cnt2 = a.cnt2;
        } else if (a.top2 == b.top1) {
            c.top2 = a.top2, c.cnt2 = a.cnt2 + b.cnt1;
        } else {
            c.top2 = b.top1, c.cnt2 = b.cnt1;
        }
    } else if (a.top1 == b.top1) {
        c.top1 = a.top1, c.cnt1 = a.cnt1 + b.cnt1;
        if (a.top2 > b.top2) {
            c.top2 = a.top2, c.cnt2 = a.cnt2;
        } else if (a.top2 == b.top2) {
            c.top2 = a.top2, c.cnt2 = a.cnt2 + b.cnt2;
        } else {
            c.top2 = b.top2, c.cnt2 = b.cnt2;
        }
    } else {
        c.top1 = b.top1, c.cnt1 = b.cnt1;
        if (b.top2 > a.top1) {
            c.top2 = b.top2, c.cnt2 = b.cnt2;
        } else if (b.top2 == a.top1) {
            c.top2 = b.top2, c.cnt2 = a.cnt1 + b.cnt2;
        } else {
            c.top2 = a.top1, c.cnt2 = a.cnt1;
        }
    }
    return c;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<Info> init(n);
    for (int i = 0; i < n; i++) {
        init[i].top1 = a[i], init[i].cnt1 = 1;
    }
    SegmentTree<Info> t(init);

    while (q--) {
        int o; cin >> o;
        if (o == 1) {
            int p, x;
            cin >> p >> x;
            p--;
            t.modify(p, {x, 1, 0, 0});
        } else {
            int l, r;
            cin >> l >> r;
            l--;
            cout << t.rangeQuery(l, r).cnt2 << endl;
        }
    }

    return 0;
}
