#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using ull = unsigned long long;
using u32 = unsigned;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int mx = *max_element(a.begin(), a.end());

    for (int i = 0; i < n; i++) {
        if ((mx - a[i]) % (2 * k) >= k) {
            mx += 2 * k - (mx - a[i]) % (2 * k);
        }
    }

    for (int i = 0; i < n; i++) {
        if ((mx - a[i]) % (2 * k) >= k) {
            mx = -1;
            break;
        }
    }
    cout << mx << "\n";
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

