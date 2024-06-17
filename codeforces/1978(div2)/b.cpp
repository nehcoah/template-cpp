#include "bits/stdc++.h"

//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;
using ll = long long;

void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    int cnt = min(n, max(0, b - a));
    cout << 1ll * (b + b - cnt + 1) * cnt / 2 + 1ll * (n - cnt) * a << endl;
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

