#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using ull = unsigned long long;
using u32 = unsigned;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<ll> sum(n + 1);
    for (int i = 0; i < n; i++) {
        sum[i + 1] = sum[i] + a[i];
    }

    auto query = [&](ll t) {
        ll x = t / n;
        ll ans = sum.back() * x;
        ll y = t % n;
        if (y) {
            if (x + y <= n) {
                ans += sum[x + y] - sum[x];
            } else {
                ans += sum[x + y - n] + sum.back() - sum[x];
            }
        }
        return ans;
    };

    while (q--) {
        ll l, r;
        cin >> l >> r;

        cout << query(r) - query(l - 1) << "\n";
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

