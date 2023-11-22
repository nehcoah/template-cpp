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

struct Tag {
    int x;
    Tag(): x(0) {}
    Tag(int x_): x(x_) {}
    void apply(Tag t) {
        if (t.x != 0) x = t.x;
    }
};

struct Info {
    int mx = 0, mn = int(1e5 + 1), sum = 0, len = 1;
    void apply(Tag t) {
        if (t.x != 0) {
            mx = t.x;
            mn = t.x;
            sum = len;
        }
    }
};

Info operator+(const Info &a, const Info &b) {
    Info c;
    c.mx = max(a.mx, b.mx);
    c.mn = min(a.mn, b.mn);
    c.sum = a.sum + b.sum;
    c.len = a.len + b.len;
    return c;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    map<array<int, 32>, int> mp;
    unordered_map<char, int> t{{'0', 0}, {'1', 1}, {'2', 2}, {'3', 3},
                               {'4', 4}, {'5', 5}, {'6', 6}, {'7', 7},
                               {'8', 8}, {'9', 9}, {'a', 10}, {'b', 11},
                               {'c', 12}, {'d', 13}, {'e', 14}, {'f', 15}};

    auto get_ip = [&](string s) {
        array<int, 32> cur{};
        stringstream io(s);
        int i = 32 - n / 16;
        while (getline(io, s, ':')) {
            cur[i] = 4096 * t[s[0]] + 256 * t[s[1]] + 16 * t[s[2]] + t[s[3]];
            i++;
        }
        return cur;
    };

    auto add = [&](array<int, 32> a) {
        a.back() += 1;
        for (int i = 31; i > 0; i--) {
            if (a[i] == 65536) a[i] = 0, a[i - 1]++;
        }
        return a;
    };

    vector<int> op(q), id(q, -1);
    vector<array<int, 32>> l(q), r(q), all;
    for (int i = 0; i < q; i++) {
        cin >> op[i];
        string s;
        if (op[i] == 1) {
            cin >> id[i];
            cin >> s;
            l[i] = get_ip(s);
            all.push_back(l[i]);
            cin >> s;
            r[i] = get_ip(s);
            all.push_back(r[i]);
            auto a = add(r[i]);
            all.push_back(a);
        } else if (op[i] == 2) {
            cin >> s;
            l[i] = get_ip(s);
            all.push_back(l[i]);
            auto a = add(l[i]);
            all.push_back(a);
        } else {
            cin >> s;
            l[i] = get_ip(s);
            all.push_back(l[i]);
            cin >> s;
            r[i] = get_ip(s);
            all.push_back(r[i]);
            auto a = add(r[i]);
            all.push_back(a);
        }
    }
    sort(all.begin(), all.end());
    all.erase(unique(all.begin(), all.end()), all.end());

    vector<Info> init(all.size() + 5);
    LazySegmentTree<Info, Tag> st(init);
    for (int i = 0; i < q; i++) {
        if (op[i] == 1) {
            int li = lower_bound(all.begin(), all.end(), l[i]) - all.begin();
            int ri = lower_bound(all.begin(), all.end(), r[i]) - all.begin();
            auto info = st.rangeQuery(li, ri + 1);
            if (info.mx == 0) {
                st.rangeApply(li, ri + 1, {id[i]});
                cout << "YES\n";
            } else {
                if (info.mx != id[i] || info.mn != id[i] || info.sum == ri - li + 1) cout << "NO\n";
                else {
                    st.rangeApply(li, ri + 1, {id[i]});
                    cout << "YES\n";
                }
            }

        } else if (op[i] == 2) {
            int li = lower_bound(all.begin(), all.end(), l[i]) - all.begin();
            cout << st.rangeQuery(li, li + 1).mx << "\n";
        } else {
            int li = lower_bound(all.begin(), all.end(), l[i]) - all.begin();
            int ri = lower_bound(all.begin(), all.end(), r[i]) - all.begin();
            auto info = st.rangeQuery(li, ri + 1);
            if (info.mx == info.mn && info.sum == ri - li + 1) cout << info.mx << "\n";
            else cout << 0 << "\n";
        }
    }

    return 0;
}


