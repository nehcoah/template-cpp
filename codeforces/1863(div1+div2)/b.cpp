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
    vector<bool> vis(n + 1);
    int ans = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] == n) {
            vis[a[i]] = 1;
            continue;
        }
        if (!vis[a[i] + 1]) ans++;
        vis[a[i]] = 1;
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
