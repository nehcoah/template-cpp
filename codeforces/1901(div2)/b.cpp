#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    ll pre = 1, ans = 0;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        if (a > pre) ans += a - pre;
        pre = a;
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


