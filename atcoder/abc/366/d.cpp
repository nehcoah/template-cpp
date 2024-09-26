#include "bits/stdc++.h"
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector a(n + 1, vector(n + 1, vector<ll>(n + 1)));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                cin >> a[i][j][k];
            }
        }
    }

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            for (int k = 0; k < n; k++) {
                a[i][j][k + 1] += a[i][j][k];
            }
        }
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k <= n; k++) {
                a[i][j + 1][k] += a[i][j][k];
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            for (int k = 0; k <= n; k++) {
                a[i + 1][j][k] += a[i][j][k];
            }
        }
    }

    int q;
    cin >> q;
    while (q--) {
        int x1, x2, y1, y2, z1, z2;
        cin >> x1 >> x2 >> y1 >> y2 >> z1 >> z2;
        ll ans = a[x2][y2][z2] - a[x1 - 1][y2][z2] - a[x2][y1 - 1][z2] - a[x2][y2][z1 - 1]
                + a[x2][y1 - 1][z1 - 1] + a[x1 - 1][y2][z1 - 1] + a[x1 - 1][y1 - 1][z2] - a[x1 - 1][y1 - 1][z1 - 1];
        cout << ans << "\n";
    }

    return 0;
}

