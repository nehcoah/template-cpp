#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    vector<string> m(3);
    for (int i = 0; i < 3; i++) {
        cin >> m[i];
    }
    for (int i = 0; i < 3; i++) {
        if (m[i].find('?') != string::npos) {
            int cnt = 0;
            for (char c : m[i]) if (c != '?') cnt += c - 'A';
            cout << char('A' + 3 - cnt) << endl;
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

