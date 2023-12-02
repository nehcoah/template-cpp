#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < q; i++) {
        ll k, ans = 0;
        cin >> k;
        auto b = a;
        for (int j = 59; j >= 0; j--) {
            auto c = b;
            ll cur = k;
            for (ll & t : c) {
                if ((t >> j & 1) == 0) {
                    cur -= (1ll << j) - (t & ((1ll << j) - 1));
                    if (cur < 0) break;
                    t += (1ll << j) - (t & ((1ll << j) - 1));
                }
            }
            if (cur >= 0) {
                k = cur;
                b = c;
                ans |= 1ll << j;
            }
        }
        cout << ans << "\n";
    }

    return 0;
}


