#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    int cnt = 0, f = 0;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        if (a < 0) cnt++;
        else if (a == 0) f = 1;
    }
    if (f || cnt % 2 == 1) cout << 0 << endl;
    else {
        cout << 1 << endl;
        cout << 1 << " " << 0 << endl;
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

