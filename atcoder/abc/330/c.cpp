#include "bits/stdc++.h"

using namespace std;
using ll = long long;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll D;
    cin >> D;
    ll ans = D;
    for (ll x = 1; x * x <= D; x++) {
        ll y = D - x * x;
        y = ll(sqrt(y));
        ans = min(ans, abs(x * x + y * y - D));
        ans = min(ans, abs(x * x + (y + 1) * (y + 1) - D));
    }
    cout << ans << endl;

    return 0;
}


