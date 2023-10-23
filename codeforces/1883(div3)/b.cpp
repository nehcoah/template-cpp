#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    vector<int> cnt(26);
    for (char c : s) cnt[c - 'a']++;
    int odd = 0, even = 0;
    for (int i = 0; i < 26; i++) {
        if (cnt[i] == 0) continue;
        (cnt[i] % 2 == 1 ? odd : even) += 1;
    }
    if (odd <= 1) cout << "YES" << endl;
    else if (odd - k <= 1) cout << "YES" << endl;
    else cout << "NO" << endl;
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

