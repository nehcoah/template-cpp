#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    string s;
    cin >> s;
    int cnt0 = 0, cnt1 = 0;
    for (char c : s) {
        (c == '0' ? cnt0 : cnt1) += 1;
    }
    for (char c : s) {
        if (c == '0') {
            if (cnt1 == 0) break;
            cnt1--;
        } else {
            if (cnt0 == 0) break;
            cnt0--;
        }
    }
    cout << max(cnt0, cnt1) << endl;
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

