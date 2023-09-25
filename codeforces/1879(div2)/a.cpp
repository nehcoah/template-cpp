#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> s(n), e(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i] >> e[i];
    }
    int ans = s[0];
    for (int i = 1; i < n; i++) {
        if (s[i] >= ans && e[i] >= e[0]) {
            cout << -1 << endl;
            return;
        }
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
