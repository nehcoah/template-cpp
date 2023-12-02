#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, L, r, t;
    cin >> n >> L >> r >> t;
    vector<vector<int>> a(n, vector<int>(n));
    vector<vector<int>> sum(n, vector<int>(n + 1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            sum[i][j + 1] = sum[i][j] + a[i][j];
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int cur = 0, cnt = 0;
            for (int x = max(0, i - r); x <= min(n - 1, i + r); x++) {
                cur += sum[x][min(n, j + r + 1)] - sum[x][max(0, j - r)];
                cnt += min(n, j + r + 1) - max(0, j - r);
            }
            if (1. * cur / cnt <= t) ans++;
        }
    }
    cout << ans << endl;

    return 0;
}


