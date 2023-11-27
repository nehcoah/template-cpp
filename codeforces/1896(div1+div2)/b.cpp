#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 0, i = 0;
    while (s[i] == 'B') i++;
    while (i < n) {
        int j = i;
        while (j < n && s[j] == 'A') j++;
        if (j == n) break;
        while (j < n && s[j] == 'B') j++;
        ans += j - i - (ans == 0);
        i = j;
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


