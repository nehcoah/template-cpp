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
    if (ranges::is_sorted(a)) {
        cout << 0 << endl;
        return;
    }
    int ans = n + 10;
    int mn = ranges::min(a), pos = -1;
    for (int i = 0; i < n; i++) {
        if (a[i] == mn && a[(i - 1 + n) % n] != mn) {
            pos = i;
            break;
        }
    }
    auto b = a;
    rotate(b.begin(), b.begin() + pos, b.end());
    if (ranges::is_sorted(b)) ans = min(n - pos, pos + 2);
    reverse(a.begin(), a.end());
    pos = -1;
    for (int i = 0; i < n; i++) {
        if (a[i] == mn && a[(i - 1 + n) % n] != mn) {
            pos = i;
            break;
        }
    }
    rotate(a.begin(), a.begin() + pos, a.end());
    if (ranges::is_sorted(a)) ans = min({ans, n - pos + 1, pos + 1});
    cout << (ans == n + 10 ? -1 : ans) << endl;
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

