#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    string s;
    cin >> s;

    auto check = [&](int x) {
        int cnt = 0;
        for (int i = 0; i + x < s.size(); i++) {
            if (s[i] == s[i + x] || s[i] == '?' || s[i + x] == '?') {
                cnt += 1;
            } else {
                cnt = 0;
            }
            if (cnt >= x) {
                return true;
            }
        }
        return false;
    };

    for (int i = s.size() / 2; i >= 0; i--) {
        if (check(i)) {
            cout << i * 2 << endl;
            return;
        }
    }
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
