#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    vector<int> fac;
    fac.push_back(1);
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            fac.push_back(i);
            if (i * i != n) fac.push_back(n / i);
        }
    }
    auto check = [&](string &t, int x) {
        int cnt = 0;
        for (int i = 0; i < n; i += x) {
            for (int j = 0; j < x; j++) {
                if (s[i + j] != t[j]) cnt += 1;
            }
        }
        return cnt;
    };
    int ans = n;
    for (int x : fac) {
        string t1 = s.substr(0, x), t2 = s.substr(x, x + x);
        int cnt = min(check(t1, x), check(t2, x));
        if (cnt <= 1) {
            ans = min(ans, x);
        }
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
