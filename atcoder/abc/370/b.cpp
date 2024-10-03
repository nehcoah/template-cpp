#include "bits/stdc++.h"
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> a[i][j];
        }
    }

    int ans = 1;
    for (int i = 1; i <= n; i++) {
        if (ans >= i) ans = a[ans - 1][i - 1];
        else ans = a[i - 1][ans - 1];
    }
    cout << ans << endl;

    return 0;
}

