#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    string s;
    cin >> s;
    vector<int> order;
    for (int i = 0, l = 0, r = n - 1; i < n; i++) {
        if (s[i] == 'L') order.push_back(a[l++]);
        else order.push_back((a[r--]));
    }
    reverse(order.begin(), order.end());
    vector<int> ans;
    int cur = 1;
    for (int i = 0; i < n; i++) {
        cur = cur * order[i] % m;
        ans.push_back(cur);
    }
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " \n"[i == n - 1];
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

