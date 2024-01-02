#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    cout << (a ^ b ^ c) << endl;
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

