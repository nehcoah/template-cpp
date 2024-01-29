#include "bits/stdc++.h"

using namespace std;
using ll = long long;

template<typename T>
struct Fenwick {
    int n;
    vector<T> tree;

    Fenwick(int n = 0) {
        init(n);
    }

    void init(int sz) {
        this->n = sz + 1;
        tree.assign(sz + 2, T());
    }

    void clear() {
        tree.assign(n + 2, T());
    }

    void add(int pos, T val) {
        pos++;
        for (; pos < tree.size(); pos += pos & -pos) tree[pos] += val;
    }

    T query(int pos) {
        pos++;
        auto ans = T();
        for (; pos; pos -= pos & -pos) ans += tree[pos];
        return ans;
    }

    T query_interval(int l, int r) {
        assert(l <= r);
        return query(r) - query(l - 1);
    }

};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<pair<int, int>> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i].first >> s[i].second;
        if (s[i].first > s[i].second) swap(s[i].first, s[i].second);
    }
    sort(s.begin(), s.end());
    Fenwick<int> t(2 * n + 1);
    for (auto [l, r] : s) {
        if (t.query_interval(l, r)) {
            cout << "Yes\n";
            return 0;
        }
        t.add(r, 1);
    }
    cout << "No\n";

    return 0;
}
