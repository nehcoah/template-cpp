#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector p(n, vector<ll>(n));
    vector r(n, vector<ll>(n - 1));
    vector d(n - 1, vector<ll>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> p[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            cin >> r[i][j];
        }
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n; j++) {
            cin >> d[i][j];
        }
    }

    const ll inf = 1e18;
    vector dp(n, vector(n, vector(n, vector<pair<ll, ll>>(n, {inf, inf}))));
    dp[0][0][0][0] = {0, 0};
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            for (int a = 0; a <= x; a++) {
                for (int b = 0; b <= y; b++) {
                    if (dp[x][y][a][b].first < inf) {
                        if (x < n - 1) {
                            ll cnt = 0;
                            auto cur = dp[x][y][a][b].second + d[x][y];
                            if (cur > 0) {
                                cnt = (cur + p[a][b] - 1) / p[a][b];
                            }
                            cur -= cnt * p[a][b];
                            int aa = a, bb = b;
                            if (p[a][b] < p[x + 1][y]) aa = x + 1, bb = y;
                            if (dp[x + 1][y][aa][bb] > make_pair(dp[x][y][a][b].first + cnt, cur)) {
                                dp[x + 1][y][aa][bb] = make_pair(dp[x][y][a][b].first + cnt, cur);
                            }
                        }
                        if (y < n - 1) {
                            ll cnt = 0;
                            auto cur = dp[x][y][a][b].second + r[x][y];
                            if (cur > 0) {
                                cnt = (cur + p[a][b] - 1) / p[a][b];
                            }
                            cur -= cnt * p[a][b];
                            int aa = a, bb = b;
                            if (p[a][b] < p[x][y + 1]) aa = x, bb = y + 1;
                            if (dp[x][y + 1][aa][bb] > make_pair(dp[x][y][a][b].first + cnt, cur)) {
                                dp[x][y + 1][aa][bb] = make_pair(dp[x][y][a][b].first + cnt, cur);
                            }
                        }
                    }
                }
            }
        }
    }

    ll ans = inf;
    for (int a = 0; a < n; a++) {
        for (int b = 0; b < n; b++) {
            ans = min(ans, dp[n - 1][n - 1][a][b].first);
        }
    }
    cout << ans + 2 * (n - 1) << endl;

    return 0;
}
