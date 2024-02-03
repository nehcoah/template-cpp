#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    long long mod = rng() % ((1ll << 61) - 1);

    int n;
    cin >> n;
    vector<ll> a(n);
    map<ll, int> mp;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        ll cur = 0;
        for (char c : s) {
            cur = ((__int128) cur * 10 + c - '0') % mod;
        }
        a[i] = cur;
        mp[cur] += 1;
    }

    int ans = 0;
    for (ll x : a) {
        for (ll y : a) {
            ll k = (__int128) x * y % mod;
            if (mp.contains(k)) {
                ans += mp[k];
            }
        }
    }
    cout << ans << endl;

    return 0;
}
