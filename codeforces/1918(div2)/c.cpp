#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    ll a, b, r;
    cin >> a >> b >> r;
    ll ans = numeric_limits<ll>::max();

    ll cur = 0;
    int i = 62;
    while (i >= 0 && (a >> i & 1) == (b >> i & 1)) i--;
    if ((1ll << i) <= r) {
        bool t = a >> i & 1;
        for (int j = i - 1; j >= 0; j--) {
            if (t && a >> j & 1 && (b >> j & 1) == 0 ||
                !t && (a >> j & 1) == 0 && b >> j & 1) {
                cur |= 1ll << j;
            }
        }
        ans = min(ans, abs((a ^ cur) - (b ^ cur)));

        cur = 1ll << i;
        for (int j = i - 1; j >= 0; j--) {
            if (!t && a >> j & 1 && (b >> j & 1) == 0 ||
                t && (a >> j & 1) == 0 && b >> j & 1) {
                if ((cur | (1 << j)) <= r) cur |= 1ll << j;
            }
        }
        ans = min(ans, abs((a ^ cur) - (b ^ cur)));
    } else {
        if (b >> i & 1) swap(a, b);
        for (; i >= 0; i--) {
            if (a >> i & 1 && (b >> i & 1) == 0) {
                if ((cur | (1ll << i)) <= r) cur |= 1ll << i;
            }
        }
        ans = min(ans, (a ^ cur) - (b ^ cur));
    }

    cout << ans << endl;
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
