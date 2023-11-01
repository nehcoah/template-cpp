#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        mp[x]++;
    }
    if (mp.size() == 1) cout << "Yes" << endl;
    else if (mp.size() == 2) {
        if (abs(mp.begin()->second - mp.rbegin()->second) <= 1) cout << "Yes" << endl;
        else cout << "No" << endl;
    } else cout << "No" << endl;
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

