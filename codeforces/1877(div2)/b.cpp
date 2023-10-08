#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    ll n, p;
    cin >> n >> p;
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    vector<int> idx(n);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int i, int j) {
        return b[i] < b[j];
    });
    ll ans = p, cnt = n - 1;
    for (int i = 0; i < n; i++) {
        int id = idx[i];
        if (b[id] > p) {
            ans += cnt * p;
            break;
        } else {
            if (cnt <= a[id]) {
                ans += b[id] * cnt;
                break;
            } else {
                ans += a[id] * b[id];
                cnt -= a[id];
            }
        }
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

