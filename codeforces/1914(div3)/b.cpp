#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;
    int cur = n - k;
    vector<int> ans(n);
    for (int i = (k == n - 1 ? 0 : 1), t = (k == n - 1 ? n - k : n - k + 1); t <= n; t++, i++) {
        ans[i] = t;
    }
    for (int i = 0; i < n; i++) {
        if (ans[i] == 0) ans[i] = cur--;
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " \n"[i == n - 1];
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

