#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> d(n);
    for (int i = 0; i < n; i++) cin >> d[i];
    int l1, c1, k1, l2, c2, k2;
    cin >> l1 >> c1 >> k1 >> l2 >> c2 >> k2;

    vector f(n + 1, vector<int>(k1 + 1, 1e5));
    f[0][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int x = 0; x <= k1; x++) {
            for (int y = 0; y <= x; y++) {
                f[i + 1][x] = min(f[i + 1][x], f[i][y] + max(0, (d[i] - (x - y) * l1 + l2 - 1) / l2));
            }
        }
    }

    ll ans = 2e18;
    for (int i = 0; i <= k1; i++) {
        if (f[n][i] > k2) continue;
        ans = min(ans, (ll)i * c1 + (ll)f[n][i] * c2);
    }
    cout << (ans > 1e18 ? -1 : ans) << endl;

    return 0;
}


//#include "bits/stdc++.h"
//
//using namespace std;
//using ll = long long;
//
//int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    int n;
//    cin >> n;
//    vector<int> d(n);
//    for (int i = 0; i < n; i++) cin >> d[i];
//    int l1, c1, k1, l2, c2, k2;
//    cin >> l1 >> c1 >> k1 >> l2 >> c2 >> k2;
//
//    vector f(n, vector<vector<ll>>(k1 + 1, vector<ll>(k2 + 1, -1)));
//    auto dfs = [&](auto self, int i, int cnt1, int cnt2) -> ll {
//        if (i == n) return 0;
//        if (f[i][cnt1][cnt2] != -1) return f[i][cnt1][cnt2];
//        int cur = d[i];
//        ll ans = 1e18;
//        for (int x = 0; x * l1 <= cur; x++) {
//            int y = (cur - x * l1 + l2 - 1) / l2;
//            if (cnt1 >= x && cnt2 >= y) {
//                ll res = self(self, i + 1, cnt1 - x, cnt2 - y) + (ll)x * c1 + (ll)y * c2;
//                ans = min(ans, res);
//            }
//        }
//        int x = (cur + l1 - 1) / l1;
//        if (cnt1 >= x) ans = min(ans, self(self, i + 1, cnt1 - x, cnt2) + (ll)x * c1);
//        return f[i][cnt1][cnt2] = ans;
//    };
//
//    ll ans = dfs(dfs, 0, k1, k2);
//    cout << (ans == 1e18 ? -1 : ans) << endl;
//
//    return 0;
//}

