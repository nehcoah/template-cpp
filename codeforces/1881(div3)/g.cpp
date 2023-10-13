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
        init(vector(n_, v_));
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

struct Tag {
    int x = 0;
    void apply(Tag t) {
        x = (x + t.x) % 26;
    }
};

struct Info {
    string pre, suf;
    int len = 0;
    bool pal = false;
    void apply(Tag t) {
        for (char &c : pre) c = char((c - 'a' + t.x) % 26 + 'a');
        for (char &c : suf) c = char((c - 'a' + t.x) % 26 + 'a');
    }
};

Info operator+(const Info& a, const Info& b) {
    Info c;
    c.len = a.len + b.len;

    if (a.len == 1) {
        c.pre = a.pre;
        if (b.len > 0) c.pre += b.pre[0];
    } else if (a.len == 0) c.pre = b.pre;
    else c.pre = a.pre;
    if (b.len == 1) {
        if (b.len > 0) c.suf += a.suf.back();
        c.suf += b.suf;
    } else if (b.len == 0) c.suf = a.suf;
    else c.suf = b.suf;

    c.pal = a.pal | b.pal;
    if (a.len >= 1 && b.len >= 1 && a.suf.back() == b.pre[0]) c.pal = true;
    if (a.len >= 2 && b.len >= 1 && a.suf[0] == b.pre[0]) c.pal = true;
    if (b.len >= 2 && a.len >= 1 && a.suf.back() == b.pre.back()) c.pal = true;

    return c;
}

void solve() {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;

    vector<Info> init(n);
    for (int i = 0; i < n; i++) {
        init[i].pre = init[i].suf = s[i];
        init[i].len = 1;
        init[i].pal = false;
    }
    LazySegmentTree<Info, Tag> ls(init);

    for (int i = 0; i < m; i++) {
        int o; cin >> o;
        if (o == 1) {
            int l, r, x;
            cin >> l >> r >> x;
            l--;
            ls.rangeApply(l, r, {x});
        } else {
            int l, r;
            cin >> l >> r;
            l--;
            auto f = ls.rangeQuery(l, r);
            cout << (f.pal ? "NO" : "YES") << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}

