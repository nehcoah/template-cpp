#include "bits/stdc++.h"

using namespace std;
using ll = long long;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<int>> a(3, vector<int>(3));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> a[i][j];
        }
    }

    vector<vector<int>> vis(3, vector<int>(3));
    auto check = [&](int x, int y) {
        bool ok = true;
        if (vis[x][(y + 1) % 3] && vis[x][(y + 2) % 3] && a[x][(y + 1) % 3] == a[x][(y + 2) % 3]) ok = false;
        if (vis[(x + 1) % 3][y] && vis[(x + 2) % 3][y] && a[(x + 1) % 3][y] == a[(x + 2) % 3][y]) ok = false;
        if (x == y && vis[(x + 1) % 3][(y + 1) % 3] && vis[(x + 2) % 3][(y + 2) % 3] && a[(x + 1) % 3][(y + 1) % 3] == a[(x + 2) % 3][(y + 2) % 3]) ok = false;
        if (x + y == 2 && vis[(x + 2) % 3][(y + 1) % 3] && vis[(x + 1) % 3][(y + 2) % 3] && a[(x + 2) % 3][(y + 1) % 3] == a[(x + 1) % 3][(y + 2) % 3]) ok = false;
        return ok;
    };

    vector<int> idx{0, 1, 2, 3, 4, 5, 6, 7, 8};
    int ans = 0;
    for (int i = 0; i < 362880; i++) {
        vis.assign(3, vector<int>(3));
        for (int id : idx) {
            int x = id / 3, y = id % 3;
            if (!check(x, y)) {
                ans++;
                break;
            }
            vis[x][y] = true;
        }
        next_permutation(idx.begin(), idx.end());
    }
    cout << fixed << setprecision(10) << double(362880 - ans) / 362880 << endl;

    return 0;
}

