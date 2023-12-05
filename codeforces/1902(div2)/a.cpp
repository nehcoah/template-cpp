#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    int z = 0, o = 0;
    for (int i = 0; i < n; i++) {
        (s[i] == '0' ? z : o) += 1;
        if (i < n - 1 && s[i] != s[i + 1]) {
            cout << "YES\n";
            return;
        }
    }
    cout << (z > o ? "YES" : "NO") << "\n";
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

