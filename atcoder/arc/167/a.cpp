#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());

    ll ans = 0;
    int j = n - 1;
    for (int i = 0; i < 2 * m - n; i++, j--) ans += a[j] * a[j];
    for (int i = 0; i < j; i++, j--) ans += (a[i] + a[j]) * (a[i] + a[j]);
    cout << ans << endl;

    return 0;
}

