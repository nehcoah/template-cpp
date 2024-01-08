#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int a, b;
    cin >> a >> b;
    cout << ((a + b) % 2 ? "Alice" : "Bob") << "\n";
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

