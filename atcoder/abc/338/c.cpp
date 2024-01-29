#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> q(n), a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> q[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    int ans = 0;
    for (int t = 0; ; t++) {
        auto cur = q;
        bool ok = true;
        for (int i = 0; i < n; i++) {
            cur[i] -= t * a[i];
            if (cur[i] < 0) ok = false;
        }
        if (!ok) break;
        int s = numeric_limits<int>::max();
        for (int i = 0; i < n; i++) {
            if (b[i] != 0) s = min(s, cur[i] / b[i]);
        }
        ans = max(ans, t + s);
    }
    cout << ans << endl;

    return 0;
}
