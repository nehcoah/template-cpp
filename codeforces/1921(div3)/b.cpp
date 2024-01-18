#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n;
    string s, t;
    cin >> n >> s >> t;

    int s1 = 0, t1 = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] != t[i]) (s[i] == '1' ? s1 : t1) += 1;
    }
    cout << max(s1, t1) << endl;
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
