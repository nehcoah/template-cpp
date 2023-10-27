#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int x, k;
    cin >> x >> k;
    for (int i = x; ; i++) {
        string s = to_string(i);
        int cur = 0;
        for (char c : s) cur += c - '0';
        if (cur % k == 0) {
            cout << i << endl;
            return;
        }
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

