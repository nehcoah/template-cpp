// 80

#include "bits/stdc++.h"

using namespace std;
using ll = long long;

template<class Info, class Tag>
struct LazySegmentTree {
    int n;
    vector<Info> info;
    vector<Tag> tag;
    LazySegmentTree() : n(0) {}
    LazySegmentTree(int n_, Info v_ = Info()) {
        init(n_, v_);
    }
    template<class T>
    LazySegmentTree(vector<T> init_) {
        init(init_);
    }
    void init(int n_, Info v_ = Info()) {
        init(vector<Info>(n_, v_));
    }
    template<class T>
    void init(vector<T> init_) {
        n = init_.size();
        info.assign(4 << int(log2(n)), Info());
        tag.assign(4 << int(log2(n)), Tag());
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
    void apply(int p, const Tag &v) {
        info[p].apply(v);
        tag[p].apply(v);
    }
    void push(int p) {
        apply(2 * p, tag[p]);
        apply(2 * p + 1, tag[p]);
        tag[p] = Tag();
    }
    void modify(int p, int l, int r, int x, const Info &v) {
        if (r - l == 1) {
            info[p] = v;
            return;
        }
        int m = (l + r) / 2;
        push(p);
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
        push(p);
        return rangeQuery(2 * p, l, m, x, y) + rangeQuery(2 * p + 1, m, r, x, y);
    }
    Info rangeQuery(int l, int r) {
        return rangeQuery(1, 0, n, l, r);
    }
    void rangeApply(int p, int l, int r, int x, int y, const Tag &v) {
        if (l >= y || r <= x) {
            return;
        }
        if (l >= x && r <= y) {
            apply(p, v);
            return;
        }
        int m = (l + r) / 2;
        push(p);
        rangeApply(2 * p, l, m, x, y, v);
        rangeApply(2 * p + 1, m, r, x, y, v);
        pull(p);
    }
    void rangeApply(int l, int r, const Tag &v) {
        return rangeApply(1, 0, n, l, r, v);
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
        push(p);
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
        push(p);
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

const int mod = 1e9 + 7;

struct Tag {
    ll a = 0, b = 0, c = 0, k = 1, s = 0;
    void apply(const Tag& t) {
        ll ta = t.a, tb = t.b, tc = t.c;
        for (int i = 0; i < s; i++) {
            swap(tb, tc);
            swap(ta, tb);
        }
        s = (s + t.s) % 3;
        k = (k * t.k % mod + mod) % mod;
        a = ((a * t.k + ta) % mod + mod) % mod;
        b = ((b * t.k + tb) % mod + mod) % mod;
        c = ((c * t.k + tc) % mod + mod) % mod;
    }
};

struct Info {
    ll sa = 0, sb = 0, sc = 0, len = 1;
    void apply(const Tag& t) {
        sa = ((sa * t.k + t.a * len) % mod + mod) % mod;
        sb = ((sb * t.k + t.b * len) % mod + mod) % mod;
        sc = ((sc * t.k + t.c * len) % mod + mod) % mod;
        for (int i = 0; i < t.s; i++) {
            swap(sa, sb);
            swap(sb, sc);
        }
    }
};

Info operator+(const Info &x, const Info &y) {
    Info z;
    z.sa = ((x.sa + y.sa) % mod + mod) % mod;
    z.sb = ((x.sb + y.sb) % mod + mod) % mod;
    z.sc = ((x.sc + y.sc) % mod + mod) % mod;
    z.len = x.len + y.len;
    return z;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    LazySegmentTree<Info, Tag> st(n + 3);

    for (int i = 0; i < m; i++) {
        int o; cin >> o;
        if (o == 1) {
            int l, r, a, b, c;
            cin >> l >> r >> a >> b >> c;
            Tag t;
            t.a = a, t.b = b, t.c = c;
            st.rangeApply(l - 1, r, t);
        } else if (o == 2) {
            int l, r, k;
            cin >> l >> r >> k;
            Tag t; t.k = k;
            st.rangeApply(l - 1, r, t);
        } else if (o == 3) {
            int l, r;
            cin >> l >> r;
            Tag t; t.s = 1;
            st.rangeApply(l - 1, r, t);
        } else {
            int l, r;
            cin >> l >> r;
            auto ans = st.rangeQuery(l - 1, r);
            cout << (ans.sa * ans.sa % mod + ans.sb * ans.sb % mod + ans.sc * ans.sc % mod) % mod << "\n";
        }
    }

    return 0;
}


