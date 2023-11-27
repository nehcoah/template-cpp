#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 0;
    for (int i = 0; i < n; ) {
        while (i < n && s[i] == '#') i++;
        int j = i;
        while (j < n && s[j] == '.') j++;
        if (j - i > 2) {
            cout << 2 << endl;
            return;
        } else {
            ans += j - i;
            i = j;
        }
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


