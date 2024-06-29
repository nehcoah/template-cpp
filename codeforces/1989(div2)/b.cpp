#include "bits/stdc++.h"
using namespace std;

using ll = long long;

void solve() {
    string a, b;
    cin >> a >> b;

    auto check = [&](int i) -> int {
        int ans = i;
        for (int j = 0; i < b.size() && j < a.size(); i++) {
            while (j < a.size() && a[j] != b[i]) j += 1;
            if (j == a.size()) break;
            j += 1;
        }
        return ans + b.size() - i;
    };

    int ans = a.size() + b.size();
    for (int i = 0; i < b.size(); i++) {
        ans = min(ans, check(i) + (int) a.size());
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
