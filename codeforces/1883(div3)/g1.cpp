#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n - 1);
    vector<int> b(n);
    for (int i = 0; i < n - 1; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    a.push_back(1);
    ranges::sort(a);
    ranges::sort(b);
    int ans = 0;
    for (int i = 0, j = 0; i < n && j < n; i++, j++) {
        while (j < n && a[i] >= b[j]) j++;
        if (j != n) ans++;
    }
    cout << n - ans << endl;
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

