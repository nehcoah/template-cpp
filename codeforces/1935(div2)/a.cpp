#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    if (s <= string(s.rbegin(), s.rend())) {
        if (n & 1) cout << s + string(s.rbegin(), s.rend()) << "\n";
        else cout << s << endl;
    } else {
        cout << string(s.rbegin(), s.rend()) + s << "\n";
    }
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
