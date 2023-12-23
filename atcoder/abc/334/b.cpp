#include "bits/stdc++.h"

using namespace std;
using ll = long long;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll a, m, l, r;
    cin >> a >> m >> l >> r;

    ll s = a - (a - l) / m * m;
    if (s < l) s += m;
    cout << (s > r ? 0 : (r - s) / m + 1) << endl;

    return 0;
}

