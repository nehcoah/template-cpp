#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int sum = 0, f = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
        if (a[i] % 3 == 1) f = 1;
    }
    if (sum % 3 == 0) cout << 0 << endl;
    else if (sum % 3 == 2) cout << 1 << endl;
    else {
        if (f) cout << 1 << endl;
        else cout << 2 << endl;
    }
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
