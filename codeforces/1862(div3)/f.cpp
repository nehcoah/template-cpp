#include "bits/stdc++.h"

#define endl '\n'
using namespace std;
using ll = long long;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;

const int N = 1e6 + 1;

void solve() {
    int w, f;
    cin >> w >> f;
    int n, sum = 0;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    bitset<N + 1> dp{};
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        dp |= dp << a[i];
        sum += a[i];
    }

    int ans = 1e9;
    for (int i = 0; i <= sum; i++) {
        if (dp[i]) ans = min(ans, max((i + w - 1) / w, (sum - i + f - 1) / f));
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
