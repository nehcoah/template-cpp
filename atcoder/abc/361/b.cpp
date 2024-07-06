#include "bits/stdc++.h"
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b, c, d, e, f, g, h, i, j, k, l;
    cin >> a >> b >> c >> d >> e >> f >> g >> h >> i >> j >> k >> l;

    int x = min(d, j) - max(a, g);
    int y = min(e, k) - max(b, h);
    int z = min(f, l) - max(c, i);
    int t = x * y * z;
    cout << (t > 0 && x > 0 && y > 0 && z > 0 ? "Yes" : "No") << endl;

    return 0;
}
