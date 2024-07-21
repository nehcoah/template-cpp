#include "bits/stdc++.h"
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;

    bool ok = true;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            break;
        }
        if (t[i] == '1') {
            ok = false;
            break;
        }
    }
    cout << (ok ? "YES" : "NO") << endl;
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
