#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    bool s_ok = true, t_ok = true, z = false, o = false;
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == s[i + 1]) {
            s_ok = false;
            if (s[i] == '0') z = true;
            if (s[i] == '1') o = true;
        }
    }
    if (s_ok) {
        cout << "Yes" << endl;
        return;
    }
    for (int i = 0; i < m - 1; i++) {
        if (t[i] == t[i + 1]) {
            t_ok = false;
            break;
        }
    }
    if (!t_ok || t[0] != t.back()) {
        cout << "No" << endl;
        return;
    }
    if (t[0] == '0') {
        if (z) cout << "No" << endl;
        else cout << "Yes" << endl;
    } else {
        if (o) cout << "No" << endl;
        else cout << "Yes" << endl;
    }
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

