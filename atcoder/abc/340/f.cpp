#include "bits/stdc++.h"

using namespace std;
using ll = long long;

template< typename T >
T extgcd(T a, T b, T &x, T &y) {
    T d = a;
    if (b != 0) {
        d = extgcd(b, a % b, y, x);
        y -= (a / b) * x;
    } else {
        x = 1;
        y = 0;
    }
    return d;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll x, y, a, b;
    cin >> a >> b;

    ll d = extgcd(a, -b, y, x);
    if (abs(d) > 2) {
        cout << -1 << endl;
    } else {
        if (abs(d) == 1) x *= 2, y *= 2;
        cout << x << " " << y << endl;
    }

    return 0;
}
