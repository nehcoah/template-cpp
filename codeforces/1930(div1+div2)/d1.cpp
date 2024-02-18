#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int pre = -1, cnt = 0;
            for (int k = i; k <= j; k++) {
                if (s[k] == '1' && (pre == -1 || pre + 1 < k)) {
                    pre = k + 1;
                    cnt++;
                }
            }
            ans += cnt;
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

