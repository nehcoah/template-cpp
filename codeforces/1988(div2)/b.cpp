#include "bits/stdc++.h"
using namespace std;

using ll = long long;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    int cnt0 = 0, cnt1 = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            int j = i;
            while (j < n && s[j] == '0') j += 1;
            cnt0 += 1;
            i = j - 1;
        } else {
            cnt1 += 1;
        }
    }
    cout << (cnt1 > cnt0 ? "Yes" : "No") << endl;
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
