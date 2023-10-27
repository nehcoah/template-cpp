#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<int> idx;
    for (int i = 0; i < n; i++) if (s[i] == '0') idx.push_back(i);
    ll ans = 0;
    bool ok = false;
    for (int i = n - 1; i >= 0; i--) {
        if (ok) cout << -1 << " ";
        else if (s[i] == '0') {
            idx.pop_back();
            cout << ans << " ";
        } else {
            if (idx.empty()) ok= true, cout << -1 << " ";
            else {
                ans += i - idx.back();
                s[idx.back()] = '1';
                idx.pop_back();
                cout << ans << " ";
            }
        }
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

