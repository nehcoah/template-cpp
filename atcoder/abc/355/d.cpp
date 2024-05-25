#include "bits/stdc++.h"

//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

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
    vector<pair<int, int>> p(n);
    vector<int> idx;
    for (int i = 0; i < n; i++) {
        cin >> p[i].first >> p[i].second;
        idx.push_back(p[i].first);
        idx.push_back(p[i].second);
    }
    sort(p.begin(), p.end(), [](auto &a, auto &b) {
        return a.second < b.second;
    });
    sort(idx.begin(), idx.end());
    idx.erase(unique(idx.begin(), idx.end()), idx.end());

    Fenwick<int> t(idx.size() + 5);
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        int l = p[i].first, r = p[i].second;
        l = lower_bound(idx.begin(), idx.end(), l) - idx.begin();
        r = lower_bound(idx.begin(), idx.end(), r) - idx.begin();
        ans += t.query_interval(l, r);
        t.add(r, 1);
    }
    cout << ans << endl;

    return 0;
}
