#include "bits/stdc++.h"

#define endl '\n'
using namespace std;
using ll = long long;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> ans{a[0]};
    for (int i = 1; i < n; i++) {
        if (a[i] < a[i - 1]) ans.push_back(min(a[i - 1], a[i]) - 1);
        if (ans.back() == 0) ans.back() += 1;
        ans.push_back(a[i]);
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) cout << ans[i] << " \n"[i == ans.size() - 1];
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
