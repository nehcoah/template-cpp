#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> x(m);
    for (int i = 0; i < m; i++) {
        cin >> x[i];
        x[i]--;
    }
    vector<ll> d(n + 1);
    for (int i = 0; i < m - 1; i++) {
        int a = x[i], b = x[i + 1];
        if (a > b) swap(a, b);
        d[a] += n - b + a;
        d[b] -= n - b + a;
        d[b] += b - a;
        d[n] -= b - a;
        d[0] += b - a;
        d[a] -= b - a;
    }
    ll ans = numeric_limits<ll>::max();
    for (int i = 0; i < n; i++) {
        ans = min(ans, d[i]);
        d[i + 1] += d[i];
    }
    cout << ans << endl;

    return 0;
}
