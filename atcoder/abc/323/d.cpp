#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    map<ll, ll> mp;
    for (int i = 0; i < n; i++) {
        int s, c;
        cin >> s >> c;
        mp[s] = c;
    }

    ll ans = 0;
    for (auto &[k, v] : mp) {
        ans += v & 1;
        if (v == 1) continue;
        mp[k * 2] += v / 2;
        v = v & 1;
    }
    cout << ans << endl;

    return 0;
}

