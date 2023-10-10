#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    string s; cin >> s;
    ll pos; cin >> pos;

    int x, n = s.size();
    for (int i = 0; i < n; i++) {
        int len = n - i;
        if (pos <= len) {
            x = n - len;
            break;
        }
        pos -= len;
    }

    string t;
    for (char c : s) {
        while (x && !t.empty() && t.back() > c) {
            t.pop_back();
            x--;
        }
        t += c;
    }
    cout << t[pos - 1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
    cout << endl;

    return 0;
}

