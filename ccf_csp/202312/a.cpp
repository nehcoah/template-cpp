#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    auto check = [&](int x, int y) {
        for (int i = 0; i < m; i++) {
            if (a[x][i] >= a[y][i]) return false;
        }
        return true;
    };
    for (int i = 0; i < n; i++) {
        bool ok = false;
        for (int j = 0; j < n; j++) {
            if (check(i, j)) {
                cout << j + 1 << "\n";
                ok = true;
                break;
            }
        }
        if (!ok) cout << 0 << "\n";
    }

    return 0;
}
