#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    vector<int> cnt(26);
    for (char c : s) {
        cnt[c - 'a']++;
    }
    int ans = 0;
    for (int i = 0; i < 26; i++) {
        ans = max(ans, max(0, cnt[i] * 2 - n));
    }
    if (n & 1) ans = max(ans, 1);
    cout << ans << endl;
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

