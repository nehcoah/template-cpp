#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    if (a < b && b < c) cout << "STAIR\n";
    else if (a < b && b > c) cout << "PEAK\n";
    else cout << "NONE\n";
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
