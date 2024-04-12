// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n), b(m);
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
        mp[b[i]] += 1;
    }
    int ans = 0, cur = 0;
    for (int i = 0; i < m; i++) {
        if (mp.count(a[i])) {
            mp[a[i]] -= 1;
            if (mp[a[i]] >= 0) cur += 1;
        }
    }
    if (cur >= k) ans += 1;
    for (int i = m; i < n; i++) {
        if (mp.count(a[i])) {
            mp[a[i]] -= 1;
            if (mp[a[i]] >= 0) cur += 1;
        }
        if (mp.count(a[i - m])) {
            mp[a[i - m]] += 1;
            if (mp[a[i - m]] > 0) cur -= 1;
        }
        if (cur >= k) ans += 1;
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
