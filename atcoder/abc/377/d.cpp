#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using ull = unsigned long long;
using u32 = unsigned;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> f(m, m);
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        l -= 1, r -= 1;
        f[l] = min(f[l], r);
    }
    for (int i = m - 2; i >= 0; i--) {
        f[i] = min(f[i], f[i + 1]);
    }
    ll ans = 0;
    for (int i = 0; i < m; i++) {
        ans += f[i] - i;
    }
    cout << ans << endl;

    return 0;
}

