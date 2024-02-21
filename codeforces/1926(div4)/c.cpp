#include "bits/stdc++.h"

using namespace std;
using ll = long long;

const int K = 2e5 + 1;
int f[K], ans[K];

void solve() {
    int n;
    cin >> n;

    cout << ans[n] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 1; i < K; i++) {
        f[i] += f[i / 10] + i % 10;
        ans[i] += ans[i - 1] + f[i];
    }

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}

