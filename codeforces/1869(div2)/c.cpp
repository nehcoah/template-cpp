#include "bits/stdc++.h"

#define endl '\n'
using namespace std;
using ll = long long;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;

void solve() {
    int n, m;
    cin >> n >> m;
    if (m == 1) {
        cout << 0 << endl;
        for (int i = 0; i < n; i++) cout << 0 << endl;
        return;
    }

    vector a(n, vector<int>(m));
    if (n > m - 2) {
        cout << m << endl;
        for (int i = 0; i < m - 1; i++) {
            int cur = i;
            for (int j = 0; j < m; j++) {
                a[i][j] = (cur++ % m);
            }
        }
        for (int i = m - 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                a[i][j] = a[i - 1][j];
            }
        }
    } else {
        cout << n + 1 << endl;
        for (int i = 0; i < n; i++) {
            int cur = i;
            for (int j = 0; j < m; j++) {
                a[i][j] = (cur++ % m);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cout << a[i][j] << " \n"[j == m - 1];
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
