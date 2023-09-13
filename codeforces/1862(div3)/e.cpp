#include "bits/stdc++.h"

#define endl '\n'
using namespace std;
using ll = long long;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;

void solve() {
    ll n, m, d;
    cin >> n >> m >> d;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    priority_queue<ll, vector<ll>, greater<>> pq;
    ll ans = 0, cur = 0;
    int pre = 0, cnt = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] <= 0) continue;
        cur += a[i];
        pq.push(a[i]);
        cnt++;
        if (cnt > m) cur -= pq.top(), pq.pop();
        ans = max(ans, cur - (i + 1) * d);
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
