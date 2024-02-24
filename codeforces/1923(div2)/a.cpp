#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int f = -1;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == 1 && f == -1) f = i;
    }
    auto check = [&](int x) {
        for (int i = x; i >= 0; i--) {
            if (a[i] == 0) return i;
        }
        return -1;
    };
    int ans = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] == 1) {
            int x = check(i);
            if (x < f) break;
            a[x] = 1;
            ans++;
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
