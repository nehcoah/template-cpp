#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    int ans = 1e9;
    for (int a = 0; a < 3; a++) {
        for (int b = 0; b < 2; b++) {
            for (int c = 0; c < 5; c++) {
                for (int d = 0; d < 3; d++) {
                    int cur = n - a * 1 - b * 3 - c * 6 - d * 10;
                    if (cur >= 0 && cur % 15 == 0) {
                        ans = min(ans, cur / 15 + a + b + c + d);
                    }
                }
            }
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
