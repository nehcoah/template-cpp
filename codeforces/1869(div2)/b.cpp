#include "bits/stdc++.h"

#define endl '\n'
using namespace std;
using ll = long long;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;

void solve() {
    int n, k, a, b;
    cin >> n >> k >> a >> b;
    a--; b--;
    vector<pair<ll, ll>> pos;
    for (int i = 0; i < n; i++) {
        ll x, y;
        cin >> x >> y;
        pos.emplace_back(x, y);
    }

    ll ans = abs(pos[a].first - pos[b].first) + abs(pos[a].second - pos[b].second);
    ll c1 = 1e12, c2 = 1e12;
    for (int i = 0; i < k; i++) {
        auto [x, y] = pos[i];
        c1 = min(c1, abs(pos[a].first - x) + abs(pos[a].second - y));
        c2 = min(c2, abs(pos[b].first - x) + abs(pos[b].second - y));
    }
    ans = min(ans, c1 + c2);
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
