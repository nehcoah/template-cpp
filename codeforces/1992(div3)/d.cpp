#include "bits/stdc++.h"
using namespace std;

using ll = long long;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    string s;
    cin >> s;

    vector<int> f(n + 2, 1e9);
    f[0] = 0;
    for (int i = 0; i < min(n + 1, m); i++) {
        if (i == n || s[i] != 'C') f[i + 1] = 0;
    }
    for (int i = 0; i < n; i++) {
        if (s[i] == 'C') continue;
        else if (s[i] == 'W') {
            if (i < n - 1 || s[i + 1] != 'C') f[i + 2] = min(f[i + 2], f[i + 1] + 1);
        } else {
            for (int j = i + 1; j <= min(i + m, n); j++) {
                if (j == n || s[j] != 'C') f[j + 1] = min(f[j + 1], f[i + 1]);
            }
        }
    }
    cout << (f.back() <= k ? "YES" : "NO") << endl;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
