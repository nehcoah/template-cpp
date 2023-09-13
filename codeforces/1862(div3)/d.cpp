#include "bits/stdc++.h"

#define endl '\n'
using namespace std;
using ll = long long;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;

void solve() {
    ll n;
    cin >> n;
    ll l = 2, r = 1e18 + 1;
    while (l < r) {
        ll mid = l + r + 1 >> 1;
        if (__int128(mid) * __int128(mid - 1) / 2 <= n) l = mid;
        else r = mid - 1;
    }
    ll cur = (l - 1) * l / 2;
    cout << l + n - cur << endl;
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
