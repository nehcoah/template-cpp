#include "bits/stdc++.h"
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector t(3, vector<int>(n));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < n; j++) {
            cin >> t[i][j];
        }
    }
    ll tot = accumulate(t[0].begin(), t[0].end(), 0ll);
    vector sum(3, vector<ll>(n + 1));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < n; j++) {
            sum[i][j + 1] = sum[i][j] + t[i][j];
        }
    }

    auto check = [&](vector<int> &o) -> array<int, 6> {
        int i = 0;
        for (; i < n; i++) {
            if (sum[o[0]][i + 1] >= (tot + 2) / 3) break;
        }
        int j = i + 1;
        for (; j < n; j++) {
            if (sum[o[1]][j + 1] - sum[o[1]][i + 1] >= (tot + 2) / 3) break;
        }
        if (j == n) return {-1, -1, -1, -1, -1, -1};
        if (sum[o[2]].back() - sum[o[2]][j + 1] >= (tot + 2) / 3) return {0, i, i + 1, j, j + 1, n - 1};
        else return {-1, -1, -1, -1, -1, -1};
    };

    vector<int> o{0, 1, 2};
    for (int i = 0; i < 6; i++) {
        auto x = check(o);
        if (x[0] != -1) {
            array<int, 6> ans{};
            for (int j = 0; j < 3; j++) {
                ans[o[j] * 2] = x[j * 2];
                ans[o[j] * 2 + 1] = x[j * 2 + 1];
            }
            for (int j = 0; j < 6; j++) {
                cout << ans[j] + 1 << " \n"[j == 5];
            }
            return;
        }
        next_permutation(o.begin(), o.end());
    }
    cout << -1 << endl;
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
