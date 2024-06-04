#include "bits/stdc++.h"

//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;
using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;
    vector a1(n, vector<int>(m)), b1(n, vector<int>(m));
    vector a2(m, vector<int>(n)), b2(m, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int x; cin >> x;
            a1[i][j] = a2[j][i] = x;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int x; cin >> x;
            b1[i][j] = b2[j][i] = x;
        }
    }

    auto check = [&](auto &a, auto &b) {
        for (int i = 0; i < a.size(); i++) {
            sort(a[i].begin(), a[i].end());
            sort(b[i].begin(), b[i].end());
        }
        sort(a.begin(), a.end(), [&](auto &x, auto &y) {
            return x[0] < y[0];
        });
        sort(b.begin(), b.end(), [&](auto &x, auto &y) {
            return x[0] < y[0];
        });
        for (int i = 0; i < a.size(); i++) {
            if (a[i] != b[i]) {
                return false;
            }
        }
        return true;
    };

    if (check(a1, b1) && check(a2, b2)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
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

