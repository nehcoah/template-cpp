#include "bits/stdc++.h"

using namespace std;
using ll = long long;

char ask(int a, int b, int c, int d) {
    cout << "? " << a << " " << b << " " << c << " " << d << endl;
    char ch; cin >> ch;
    return ch;
}

void solve() {
    int n;
    cin >> n;
    int mx = 0;
    for (int i = 1; i < n; i++) {
        if (ask(mx, mx, i, i) == '<') mx = i;
    }
    int ans = 0;
    for (int i = 1; i < n; i++) {
        char c = ask(i, mx, ans, mx);
        if (c == '>' || (c == '=' && ask(i, i, ans, ans) == '<')) {
            ans = i;
        }
    }
    cout << "! " << mx << " " << ans << endl;
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
