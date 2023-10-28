#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> frt(n), lst(n);
    set<int> st;
    for (int i = 0; i < n; i++) {
        if (st.count(a[i]) == 0) {
            frt[i] = 1;
            st.insert(a[i]);
        }
    }
    st.clear();
    for (int i = n - 1; i >= 0; i--) {
        if (st.count(a[i]) == 0) {
            lst[i] = 1;
            st.insert(a[i]);
        }
    }
    ll ans = 0, cur = 0;
    for (int i = 0; i < n; i++) {
        cur += frt[i];
        if (lst[i]) ans += cur;
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

