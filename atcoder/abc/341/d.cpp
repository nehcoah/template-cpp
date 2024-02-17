#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m, k;
    cin >> n >> m >> k;

    ll L = lcm(n, m);
    ll ans = *ranges::partition_point(ranges::iota_view(0ll, ll(4e18)), [&](ll x) {
        return x / n + x / m - x / L * 2 < k;
    });
    cout << ans << endl;

    return 0;
}

