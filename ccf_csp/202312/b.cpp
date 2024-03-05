#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    ll n, k;
    cin >> n >> k;
    map<ll, int> mp;
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            mp[i] += 1;
            n /= i;
        }
    }
    if (n > 1) mp[n] += 1;
    ll ans = 1;
    for (auto it = mp.begin(); it != mp.end(); it++) {
        if (it->second >= k) {
            for (int i = 0; i < it->second; i++) {
                ans *= it->first;
            }
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;

    while (q--) {
        solve();
    }

    return 0;
}
