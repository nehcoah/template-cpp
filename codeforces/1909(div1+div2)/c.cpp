#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<ll> c(n);
    vector<pair<int, int>> a;
    for (int i = 0; i < n; i++) {
        int l; cin >> l;
        a.emplace_back(l, 1);
    }
    for (int i = 0; i < n; i++) {
        int r; cin >> r;
        a.emplace_back(r, -1);
    }
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    ranges::sort(a);
    vector<ll> s, stk;
    for (auto [x, p] : a) {
        if (p == 1) {
            stk.push_back(x);
        } else {
            s.push_back(x - stk.back());
            stk.pop_back();
        }
    }
    ranges::sort(s);
    ranges::sort(c, greater<>());
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans += s[i] * c[i];
    }
    cout << ans << endl;
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

