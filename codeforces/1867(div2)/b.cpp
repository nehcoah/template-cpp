#include "bits/stdc++.h"

#define endl '\n'
using namespace std;
using ll = long long;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    unordered_set<int> st;
    int cnt = 0, cnt1 = 0;
    for (int i = 0; i < n / 2; i++) {
        if (s[i] == s[n - i - 1]) cnt++;
        else cnt1++;
    }
    for (int c = cnt1, i = 0; i <= cnt; i++) {
        st.insert(c + i * 2);
        if (n % 2 == 1) st.insert(c + i * 2 + 1);
    }
    for (int i = 0; i < n + 1; i++) {
        if (st.count(i)) cout << 1;
        else cout << 0;
    }
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
