#include "bits/stdc++.h"

using namespace std;
using ll = long long;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<int> ans(k), idx(n);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int i, int j) {return a[i] > a[j];});
    set<int> st;
    for (int i : idx) {
        int s = !st.empty() && *st.begin() < i ? *st.begin() : i;
        int e = !st.empty() && *st.rbegin() > i ? *st.rbegin() : i;
        ans[a[i] - 1] = 2 * (e - s + 1);
        st.insert(i);
    }
    for (int i = 0; i < k; i++) cout << ans[i] << " \n"[i == k - 1];
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
