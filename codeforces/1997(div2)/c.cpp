#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using ull = unsigned long long;
using u32 = unsigned;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 0, sum = 0; i < n; i++) {
        if (i % 2 == 0) s[i] = sum > 0 ? ')' : '(';
        sum += s[i] == '(' ? 1 : -1;
    }

    int ans = 0;
    vector<int> stk;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') stk.push_back(i);
        else ans += i - stk.back(), stk.pop_back();
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

