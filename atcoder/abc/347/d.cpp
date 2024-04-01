#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll a, b, c;
    cin >> a >> b >> c;

    ll x = 0, y = 0;
    ll cnt = __builtin_popcountll(c);
    if (a + b < cnt || 120 - a - b < cnt) {
        cout << -1 << endl;
        return 0;
    }

    for (int i = 0; i < 60; i++) {
        if (c >> i & 1) {
            if (a > b) x |= 1ll << i, a -= 1;
            else y |= 1ll << i, b -= 1;
        }
    }
    if (a != b) {
        cout << -1 << endl;
        return 0;
    }
    for (int i = 0; i < 60 && a && b; i++) {
        if ((c >> i & 1) == 0) {
            a -= 1; b -= 1;
            x |= 1ll << i, y |= 1ll << i;
        }
    }
    if (a == 0 && b == 0) cout << x << " " << y << endl;
    else cout << -1 << endl;

    return 0;
}
