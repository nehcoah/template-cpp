#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using ull = unsigned long long;
using u32 = unsigned;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> k(n);
    for (int i = 0; i < n; i++) {
        cin >> k[i];
    }

    ll tot = accumulate(k.begin(), k.end(), 0ll);
    ll ans = tot;
    for (int mask = 0; mask < 1 << n; mask++) {
        ll cur = 0;
        for (int i = 0; i < n; i++) {
            if (mask >> i & 1) cur += k[i];
        }
        ans = min(ans, max(cur, tot - cur));
    }
    cout << ans << endl;

    return 0;
}

