#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        sum += x;
    }
    ll s = sqrt(sum);
    if (s * s == sum) cout << "YES" << endl;
    else cout << "NO" << endl;
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

