#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using ull = unsigned long long;
using u32 = unsigned;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n >> x;
    vector<int> a(n), p(n), b(n), q(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> p[i] >> b[i] >> q[i];
        if (a[i] * q[i] < b[i] * p[i]) {
            swap(a[i], b[i]);
            swap(p[i], q[i]);
        }
    }

    auto check = [&](ll t) {
        ll tot = 0;
        for (int i = 0; i < n; i++) {
            ll cur = 1e18;
            for (int j = 0; j <= 100; j++) {
                ll v = j * q[i];
                ll r = t - j * b[i];
                if (r > 0) {
                    v += 1ll * (r + a[i] - 1) / a[i] * p[i];
                }
                cur = min(cur, v);
            }
            tot += cur;
            if (tot > x) return false;
        }
        return true;
    };

    ll l = 0, r = 1e10;
    while (l < r) {
        ll mid = (l + r + 1) >> 1;
        if (check(mid)) l = mid;
        else r = mid - 1;
    }
    cout << l << endl;

    return 0;
}

