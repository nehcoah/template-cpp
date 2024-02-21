#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    string s;
    cin >> s;
    int a = 0, b = 0;
    for (char c : s) {
        (c == 'A' ? a : b) += 1;
    }
    cout << (a > b ? "A" : "B") << "\n";
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

