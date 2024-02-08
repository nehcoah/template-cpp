#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), nxt(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    nxt[n - 1] = n;
    for (int i = n - 2; i >= 0; i--) {
        nxt[i] = a[i] == a[i + 1] ? nxt[i + 1] : i + 1;
    }
    int q; cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        if (nxt[l] <= r) cout << l + 1 << " " << nxt[l] + 1 << endl;
        else cout << -1 << " " << -1 << endl;
    }
    cout << endl;
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
