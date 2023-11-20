#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    if (k < n + m - 2 || (k - m - n + 2) % 2 == 1) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    if ((k - m - n + 2) % 4 == 0) {
        int f = 1;
        for (int i = 0; i < m - 1; i++, f ^= 1) cout << (f ? "R" : "B") << " \n"[i == m - 2];
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m - 1; j++) cout << "R" << " \n"[j == m - 2];
        }
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < m - 1; j++) cout << "B ";
            cout << (f ? "R" : "B") << "\n";
            f ^= 1;
        }
    } else {
        int f = 1;
        cout << "R ";
        for (int i = 1; i < m - 1; i++, f ^= 1) cout << (f ? "R" : "B") << " \n"[i == m - 2];
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m - 1; j++) cout << "R" << " \n"[j == m - 2];
        }
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < m - 1; j++) cout << "B ";
            cout << (f ? "R" : "B") << "\n";
            f ^= 1;
        }
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


