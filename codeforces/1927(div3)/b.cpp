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
    vector<unordered_set<char>> st(1);
    for (char c = 'a'; c <= 'z'; c++) {
        st[0].insert(c);
    }
    string ans;
    for (int i = 0; i < n; i++) {
        ans += *st[a[i]].begin();
        if (st.size() == a[i] + 1) st.emplace_back();
        st[a[i] + 1].insert(*st[a[i]].begin());
        st[a[i]].erase(st[a[i]].begin());
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
