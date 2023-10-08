#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll xa, ya, xb, yb, xc, yc;
    cin >> xa >> ya >> xb >> yb >> xc >> yc;

    auto dis = [&](ll x1, ll y1, ll x2, ll y2) {
        // (x1, y1) -> (x2, y2)
        ll ans = abs(x1 - x2) + abs(y1 - y2);
        if (x1 == x2 && xb == x1) {
            if (y1 < yb && yb < y2 || y1 > yb && yb > y2) ans += 2;
        } else if (y1 == y2 && yb == y1) {
            if (x1 < xb && xb < x2 || x1 > xb && xb > x2) ans += 2;
        }
        return ans;
    };

    if (xb == xc) {
        ll ans = abs(yb - yc);
        ll x = xb, y = yb > yc ? yb + 1 : yb - 1;
        ans += dis(x, y, xa, ya);
        cout << ans << endl;
    } else if (yb == yc) {
        ll ans = abs(xb - xc);
        ll x = xb > xc ? xb + 1 : xb - 1, y = yb;
        ans += dis(x, y, xa, ya);
        cout << ans << endl;
    } else {
        ll ans = abs(xb - xc) + abs(yb - yc) + 2;
        ll x = xb, y = yb < yc ? yb - 1 : yb + 1;
        ll cur = dis(x, y, xa, ya);
        x = xb < xc ? xb - 1 : xb + 1, y = yb;
        cur = min(cur, dis(x, y, xa, ya));
        ans += cur;
        cout << ans << endl;
    }

    return 0;
}

