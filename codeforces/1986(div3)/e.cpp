#include "bits/stdc++.h"
using namespace std;

using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    map<int, vector<int>> mp;
    for (int i = 0; i < n; i++) {
        mp[a[i] % k].push_back(a[i]);
    }

    ll ans = 0;
    int cnt = 0;
    for (auto &[x, v] : mp) {
        if (v.size() % 2 == 1) {
            cnt += 1;
            vector<ll> p{0}, q{0};
            for (int i = 0; i < v.size() - 1; i++) {
                if (i % 2) q.push_back(q.back() + v[i + 1] - v[i]);
                else p.push_back(p.back() + v[i + 1] - v[i]);
            }
            ll cur = 1e18;
            for (int i = 0; i < p.size(); i++) {
                cur = min(cur, p[i] + q.back() - q[i]);
            }
            ans += cur / k;
        } else {
            ll cur = 0;
            for (int i = 0; i < v.size() - 1; i += 2) cur += (v[i + 1] - v[i]) / k;
            ans += cur;
        }
    }
    if (cnt > 1) cout << -1 << endl;
    else cout << ans << endl;
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
