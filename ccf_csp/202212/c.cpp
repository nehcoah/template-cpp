#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<int>> Q(8, vector<int>(8)), M(8, vector<int>(8));
    int n, T;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cin >> Q[i][j];
        }
    }
    cin >> n >> T;
    for (int i = 0, x = 0, y = 0; i < n; i++) {
        cin >> M[x][y];
        if ((x + y) % 2 == 1) {
            if (x == min(x + y, 7)) x == 7 ? y++ : x++;
            else x++, y--;
        } else {
            if (y == min(x + y, 7)) y == 7 ? x++ : y++;
            else x--, y++;
        }
    }
    if (T == 0) {
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                cout << M[i][j] << " \n"[j == 7];
            }
        }
        return 0;
    }

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            M[i][j] *= Q[i][j];
        }
    }
    if (T == 1) {
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                cout << M[i][j] << " \n"[j == 7];
            }
        }
        return 0;
    }

    const double A = sqrt(0.5);
    const double pi = acos(-1);
    auto M_ = M;
    auto alpha = [&](int u) {
        if (u == 0) return A;
        else return 1.;
    };
    auto transform = [&](int i, int j) {
        double ans = 0;
        for (int u = 0; u < 8; u++) {
            for (int v = 0; v < 8; v++) {
                double cur = alpha(u) * alpha(v) * M_[u][v];
                cur *= cos(pi / 8 * (i + 0.5) * u);
                cur *= cos(pi / 8 * (j + 0.5) * v);
                ans += cur;
            }
        }
        return ans / 4;
    };
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            M[i][j] = int(round(transform(i, j) + 128));
            if (M[i][j] > 255) M[i][j] = 255;
            if (M[i][j] < 0) M[i][j] = 0;
        }
    }
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cout << M[i][j] << " \n"[j == 7];
        }
    }

    return 0;
}


