#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using ull = unsigned long long;
using u32 = unsigned;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int m;
    cin >> m;
    while (m--) {
        string s; cin >> s;
        unordered_map<char, int> mp1;
        unordered_map<int, char> mp2;
        if (s.size() != a.size()) {
            cout << "NO\n";
            continue;
        }
        bool ok = true;
        for (int i = 0; i < n; i++) {
            if (!mp1.contains(s[i])) {
                mp1[s[i]] = a[i];
            } else {
                if (mp1[s[i]] != a[i]) {
                    cout << "NO\n";
                    ok = false;
                    break;
                }
            }
            if (!mp2.contains(a[i])) {
                mp2[a[i]] = s[i];
            } else {
                if (mp2[a[i]] != s[i]) {
                    cout << "NO\n";
                    ok = false;
                    break;
                }
            }
        }
        if (!ok) continue;
        cout << "YES\n";
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

