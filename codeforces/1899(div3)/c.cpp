#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int ans = -1e4;
    for (int i = 0; i < n; i++) {
        ans = max(ans, a[i]);
        if (a[i] <= 0) continue;
        int f = a[i] % 2, j = i, sum = 0;
        while (j < n) {
            if (abs(a[j] % 2) == f) {
                sum += a[j];
                f ^= 1;
                ans = max(ans, sum);
                if (sum < 0) {
                    i = j;
                    break;
                }
                j++;
            } else {
                i = j - 1;
                break;
            }
        }
        if (j == n) i = n;
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


