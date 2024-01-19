#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    ll x;
    cin >> x;
    if (x == 1) {
        cout << 0 << "\n";
        return;
    }
    int cnt = -1;
    vector<int> ans;
    for (int i = 63; i >= 0; i--) {
        if (x >> i & 1) {
            if (ans.empty()) {
                cnt = i;
                for (int j = cnt; j; j--) {
                    ans.push_back(j);
                }
            } else {
                ans.push_back(cnt - i);
            }
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " \n"[i == ans.size() - 1];
    }
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
