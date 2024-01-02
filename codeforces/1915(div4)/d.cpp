#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n;
    string s;
    cin >> n >> s;

    auto check = [&](char c) {
        return c == 'b' || c == 'c' || c == 'd';
    };

    cout << s[0];
    for (int i = 1; i < n; i++) {
        if (check(s[i])) {
            if (i == n - 1 || check(s[i + 1])) cout << s[i];
            else cout << "." << s[i];
        } else cout << s[i];
    }
    cout << endl;
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

