#include "bits/stdc++.h"
using namespace std;

using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;
    vector a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    if (n == 1 && m == 1) {
        cout << -1 << endl;
        return;
    }
    for (int i = 0; i < n; i++) {
        rotate(a[i].begin(), a[i].begin() + 1, a[i].end());
    }
    if (m == 1) {
        for (int i = 0; i < n - 1; i++) {
            swap(a[i][0], a[i + 1][0]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << a[i][j] << " \n"[j == m - 1];
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
