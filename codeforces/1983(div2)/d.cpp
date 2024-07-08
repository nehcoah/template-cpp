#include "bits/stdc++.h"
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    auto x = a, y = b;
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    if (x != y) {
        cout << "NO\n";
        return;
    }
    for (int i = 0; i < n; i++) {
        a[i] = lower_bound(x.begin(), x.end(), a[i]) - x.begin();
        b[i] = lower_bound(y.begin(), y.end(), b[i]) - y.begin();
    }
    auto check = [&](vector<int> &z) {
        vector<int> vis(n);
        int p = n % 2;
        for (int i = 0; i < n; i++) {
            if (vis[i]) continue;
            for (int j = i; !vis[j]; j = z[j]) {
                vis[j] = 1;
            }
            p ^= 1;
        }
        return p;
    };
    if (check(a) != check(b)) cout << "NO\n";
    else cout << "YES\n";
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
