#include "bits/stdc++.h"

using namespace std;
using ll = long long;
const int mod = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m, p;
    cin >> n >> m >> p;
    vector<ll> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());
    ll ans = 0;
    vector<ll> sum(m + 1);
    for (int i = 0; i < m; i++) sum[i + 1] = sum[i] + b[i];

    for (int i = 0; i < n; i++) {
        ll t = p - a[i];
        int idx = upper_bound(b.begin(), b.end(), t) - b.begin() - 1;
        if (idx == -1) ans += p * m;
        else ans += sum[idx + 1] + a[i] * (idx + 1) + p * (m - idx - 1);
    }

    cout << ans << endl;

    return 0;
}
