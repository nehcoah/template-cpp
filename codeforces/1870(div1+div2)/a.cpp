#include "bits/stdc++.h"

using namespace std;
using ll = long long;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;

void solve() {
    int n, k, x;
    cin >> n >> k >> x;
    if (x + 1 < k || n < k) {
        cout << -1 << endl;
        return;
    }
    int ans = 0;
    for (int i = 0, cnt = 0; i < n; i++) {
        ans += cnt;
        if (cnt == x) continue;
        else if (cnt + 1 == k) {
            if (x > k) cnt = x;
        } else cnt++;
    }
    cout << ans << endl;
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
