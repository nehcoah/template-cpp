#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    string s;
    cin >> s;
    for (int i = 1; i <= 8; i++) {
        if (i != s[1] - '0') cout << s[0] << i << endl;
    }
    for (char c = 'a'; c <= 'h'; c++) {
        if (c != s[0]) cout << c << s[1] << endl;
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

