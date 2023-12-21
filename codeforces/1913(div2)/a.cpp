#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    string s;
    cin >> s;
    for (int i = 1; i <= s.size() / 2; i++) {
        string s1 = s.substr(0, i);
        string s2 = s.substr(i);
        if (s1[0] == '0' || s2[0] == '0') continue;
        int n1 = stoi(s1), n2 = stoi(s2);
        if (n1 < n2) {
            cout << n1 << " " << n2 << endl;
            return;
        }
    }
    cout << -1 << endl;
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

