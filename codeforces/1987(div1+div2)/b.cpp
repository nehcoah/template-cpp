#include "bits/stdc++.h"
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> t;
    int mx = a[0];
    for (int i = 1; i < n; i++) {
        if (mx > a[i]) {
            t.push_back(mx - a[i]);
        } else {
            mx = a[i];
        }
    }
    sort(t.begin(), t.end());
    ll ans = 0, x = 0;
    for (int i = 0; i < t.size(); i++) {
        if (t[i] - x > 0) ans += 1ll * (t[i] - x) * (t.size() - i + 1);
        x = t[i];
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}
