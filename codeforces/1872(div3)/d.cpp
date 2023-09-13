#include "bits/stdc++.h"

#define endl '\n'
using namespace std;
using ll = long long;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;

void solve() {
    ll n, x, y;
    cin >> n >> x >> y;
    ll add = n / x - n / lcm(x, y), sub = n / y - n / lcm(x, y);
    ll ans = (n + n - add + 1) * add / 2 - (1 + sub) * sub / 2;
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
