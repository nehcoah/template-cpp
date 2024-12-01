#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using ull = unsigned long long;
using u32 = unsigned;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> q(n), r(n);
    for (int i = 0; i < n; i++) {
        cin >> q[i] >> r[i];
    }
    int Q;
    cin >> Q;
    while (Q--) {
        int t, d;
        cin >> t >> d;
        t -= 1;
        ll ans = d + (d % q[t] == r[t] ? 0 : (d % q[t] < r[t] ? r[t] - d % q[t] : q[t] + r[t] - d % q[t]));
        cout << ans << "\n";
    }

    return 0;
}

