#include "bits/stdc++.h"
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, x, y;
    cin >> n >> x >> y;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    sort(a.begin(), a.end(), greater());
    sort(b.begin(), b.end(), greater());
    ll A = 0, B = 0, ans = n;
    for (int i = 0; i < n; i++) {
        A += a[i];
        B += b[i];
        if (A > x) ans = min(ans, (ll) i + 1);
        if (B > y) ans = min(ans, (ll) i + 1);
    }
    cout << ans << endl;

    return 0;
}
