#include "bits/stdc++.h"

//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<int>> f{
        {0, 0, 0, 0, 0},
        {0, 2, 3, 5, 6},
        {0, 3, 6, 9, 12},
        {0, 3, 7, 10, 14},
        {0, 4, 8, 12, 16}
    };

    ll a, b, c, d;
    cin >> a >> b >> c >> d;

    if (a < 0) {
        ll t = (abs(a / 4) + 1) * 4;
        a += t;
        c += t;
    }
    if (b < 0) {
        ll t = (abs(b / 4) + 1) * 4;
        b += t;
        d += t;
    }

    auto check = [&](ll x, ll y) {
        ll X = x / 4 * 4, Y = y / 4 * 4;
        ll ans = 1ll * X * Y;
        ans += X / 4 * f[4][y - Y];
        ans += Y / 4 * f[x - X][4];
        ans += f[x - X][y - Y];
        return ans;
    };

    cout << check(c, d) - check(a, d) - check(c, b) + check(a, b) << endl;

    return 0;
}
