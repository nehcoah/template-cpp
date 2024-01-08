#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int s = n + 1, t = n + 1, ans = 0;
    for (int x : a) {
        if (x > s && x > t) {
            ans++;
            (s < t ? s : t) = x;
        } else if (x <= s && x <= t) {
            (s < t ? s : t) = x;
        } else if (x > s) {
            t = x;
        } else {
            s = x;
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

