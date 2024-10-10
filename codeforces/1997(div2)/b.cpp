#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using ull = unsigned long long;
using u32 = unsigned;

void solve() {
    int n;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;
    int ans = 0;
    for (int i = 1; i < n - 1; i++) {
        if (s1[i - 1] == '.' && s1[i + 1] == '.' && s2[i] == '.' && s2[i - 1] == 'x' && s2[i + 1] == 'x') ans += 1;
        if (s2[i - 1] == '.' && s2[i + 1] == '.' && s1[i] == '.' && s1[i - 1] == 'x' && s1[i + 1] == 'x') ans += 1;
    }
    cout << ans << "\n";
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

