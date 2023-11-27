#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;

    auto check = [&](int x, int y, int z) {
        int diff = abs(x - y);
        if (diff % 2 == 0 && diff / 2 <= z || (diff - 2 * z) % 2 == 0) return true;
        else return false;
    };

    cout << check(b, c, a) << " " << check(a, c, b) << " " << check(a, b, c) << endl;
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


