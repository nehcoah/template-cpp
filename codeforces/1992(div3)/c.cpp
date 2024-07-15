#include "bits/stdc++.h"
using namespace std;

using ll = long long;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = n; i > m; i--) {
        cout << i << " ";
    }
    for (int i = 1; i <= m; i++) {
        cout << i << " \n"[i == m];
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
