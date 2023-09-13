#include "bits/stdc++.h"

#define endl '\n'
using namespace std;
using ll = long long;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = 0; i < n - 1; i++) {
        int cnt = 0;
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 'U' && a[i + 1][j] == 'D') {
                if (cnt == 0) a[i][j] = 'W', a[i + 1][j] = 'B';
                else a[i][j] = 'B', a[i + 1][j] = 'W';
                cnt ^= 1;
            }
        }
        if (cnt == 1) {
            cout << -1 << endl;
            return;
        }
    }

    for (int i = 0; i < m - 1; i++) {
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if (a[j][i] == 'L' && a[j][i + 1] == 'R') {
                if (cnt == 0) a[j][i] = 'W', a[j][i + 1] = 'B';
                else a[j][i] = 'B', a[j][i + 1] = 'W';
                cnt ^= 1;
            }
        }
        if (cnt == 1) {
            cout << -1 << endl;
            return;
        }
    }

    for (int i = 0; i < n; i++) cout << a[i] << endl;
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
