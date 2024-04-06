#include "bits/stdc++.h"

using namespace std;
using ll = long long;

string s = "AABB";

void solve() {
    int n;
    cin >> n;
    if (n % 2 == 1) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    cout << s.substr(0, n) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 0; i < 5; i++) {
        s += s;
    }

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
