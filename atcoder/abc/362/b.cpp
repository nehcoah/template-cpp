#include "bits/stdc++.h"
using namespace std;

using ll = long long;

int main() {
    int xa, ya, xb, yb, xc, yc;
    cin >> xa >> ya >> xb >> yb >> xc >> yc;

    auto check = [&](int a, int b, int c, int d) {
        return (c - a) * (c - a) + (d - b) * (d - b);
    };

    int x = check(xa, ya, xb, yb);
    int y = check(xa, ya, xc, yc);
    int z = check(xb, yb, xc, yc);

    if (max({x, y, z}) == x + y + z - max({x, y, z})) cout << "Yes\n";
    else cout << "No\n";

    return 0;
}
