#include "bits/stdc++.h"
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    const ll mod = (1ll << 61) - 1;

    int n, q;
    cin >> n >> q;
    vector<ll> pw(n + 1);
    for (int i = 0; i <= n; i++) {
        pw[i] = uniform_int_distribution<ll>(1, mod - 1)(rng);
    }
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    vector<ll> ha(n + 1), hb(n + 1);
    for (int i = 0; i < n; i++) {
        ha[i + 1] = (ha[i] + pw[a[i]]) % mod;
        hb[i + 1] = (hb[i] + pw[b[i]]) % mod;
    }

    while (q--) {
        int l, r, L, R;
        cin >> l >> r >> L >> R;
        if (((ha[r] - ha[l - 1]) % mod + mod) % mod == ((hb[R] - hb[L - 1]) % mod + mod) % mod) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }

    return 0;
}

