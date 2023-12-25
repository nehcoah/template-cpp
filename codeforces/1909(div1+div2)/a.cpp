#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    ranges::sort(x);
    ranges::sort(y);
    int cnt = 0;
    if (x[0] < 0) cnt++;
    if (x.back() > 0) cnt++;
    if (y[0] < 0) cnt++;
    if (y.back() > 0) cnt++;
    cout << (cnt == 4 ? "NO" : "YES") << endl;
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

