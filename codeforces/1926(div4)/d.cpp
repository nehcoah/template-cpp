#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    multiset<int> st;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        st.insert(x);
    }
    int ans = 0, mx = numeric_limits<int>::max();
    while (!st.empty()) {
        ans++;
        int x = *st.begin();
        st.erase(st.begin());
        auto it = st.find(x ^ mx);
        if (it != st.end()) st.erase(it);
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

