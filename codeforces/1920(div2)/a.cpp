#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    int mx = 1e9, mn = 0;
    vector<int> nq;
    for (int i = 0; i < n; i++) {
        int o, x;
        cin >> o >> x;
        if (o == 1) mn = max(mn, x);
        else if (o == 2) mx = min(mx, x);
        else nq.push_back(x);
    }
    int ans = mx - mn + 1;
    for (int x : nq) {
        if (x >= mn && x <= mx) ans--;
    }
    cout << max(ans, 0) << endl;
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
