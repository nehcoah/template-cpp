#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll ans = (1 + k) * k / 2;
    set<int> st;
    for (int i = 0; i < n; i++) {
        if (a[i] <= k && st.count(a[i]) == 0) {
            ans -= a[i];
            st.insert(a[i]);
        }
    }
    cout << ans << endl;

    return 0;
}
