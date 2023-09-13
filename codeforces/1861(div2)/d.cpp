#include "bits/stdc++.h"

#define endl '\n'
using namespace std;
using ll = long long;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int cnt = 0;
    for (int i = 0; i < n - 1; i++) if (a[i] >= a[i + 1]) cnt++;
    int ans = n, cnt1 = 0;
    for (int i = 0; i < n; i++) {
        bool f = (i > 0);
        ans = min(ans, f + cnt + cnt1);
        if (i + 1 < n && a[i] >= a[i + 1]) cnt--;
        if (i > 0 && a[i - 1] <= a[i]) cnt1++;
    }
    ans = min(ans, 1 + cnt + cnt1);
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
