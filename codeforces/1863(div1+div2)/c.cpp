#include "bits/stdc++.h"

#define endl '\n'
using namespace std;
using ll = long long;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    if (k == 0) {
        for (int i = 0; i < n; i++) cout << a[i] << " \n"[i == n - 1];
        return;
    }
    set<int> st;
    for (int i = 0; i <= n; i++) st.insert(i);
    vector<int> f(n + 1);
    for (int i = 0; i < n; i++) {
        if (st.count(a[i])) st.erase(st.find(a[i]));
        f[a[i]]++;
    }
    for (int i = 0; i < n; i++) {
        int x = a[i];
        f[x]--;
        a[i] = *st.begin();
        st.erase(st.begin());
        if (f[x] == 0) st.insert(x);
    }

    k--;
    vector<bool> vis(n + 1);
    int cur;
    for (int i = 0; i < n; i++) vis[a[i]] = 1;
    for (int i = 0; i < n + 1; i++) if (!vis[i]) cur = i;
    int diff = k % (n + 1);
    a.push_back(cur);
    for (int i = diff == 0 ? 0 : n + 1 - diff, cnt = 0; cnt < n; cnt++, i = (i + 1) % (n + 1)) cout << a[i] << " ";
    cout << endl;
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
