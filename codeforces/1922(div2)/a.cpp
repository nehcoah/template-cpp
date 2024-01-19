#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n, cnt = 0;
    string a, b, c;
    cin >> n >> a >> b >> c;
    for (int i = 0; i < n; i++) {
        if (c[i] == a[i] || c[i] == b[i]) {
            cnt++;
        }
    }
    cout << (cnt == n ? "NO\n" : "YES\n");
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
