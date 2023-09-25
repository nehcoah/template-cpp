#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    ll mn_a = *min_element(a.begin(), a.end());
    ll mn_b = *min_element(b.begin(), b.end());

    ll ans = min(accumulate(a.begin(), a.end(), 0LL) + n * mn_b, accumulate(b.begin(), b.end(), 0LL) + n * mn_a);
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
