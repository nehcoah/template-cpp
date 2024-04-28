//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    auto check = [&](char c) {
        int cnt = 0;
        for (int i = 0; i < m; i++) {
            if (s[0][i] == c) cnt |= 1;
            if (s[n - 1][i] == c) cnt |= 2;
        }
        for (int i = 0; i < n; i++) {
            if (s[i][0] == c) cnt |= 4;
            if (s[i][m - 1] == c) cnt |= 8;
        }
        return cnt == 15;
    };

    cout << (check('W') || check('B') ? "YES\n" : "NO\n");
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
