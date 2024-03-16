#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll x;
    cin >> x;
    if (x >= 0) cout << (x + 9) / 10 << endl;
    else cout << x / 10 << endl;

    return 0;
}
