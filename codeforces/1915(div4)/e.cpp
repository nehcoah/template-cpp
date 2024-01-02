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
    set<ll> st{0};
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        sum = sum + a[i] * (i % 2 == 0 ? 1 : -1);
        if (st.contains(sum)) {
            cout << "YES" << endl;
            return;
        }
        st.insert(sum);
    }
    cout << "NO" << endl;
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

