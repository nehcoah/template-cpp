#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> cnt(26);
    int d = 0, ans = 0;
    for (char c : s) {
        if (cnt[c - 'a'] == 0) d++;
        cnt[c - 'a']++;
        ans += d;
    }
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

