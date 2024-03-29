#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<string> ans;
    string s, t;
    for (int i = 0; i < n; i++) {
        s += string(2, i % 2 == 0 ? '#' : '.');
        t += string(2, i % 2 == 0 ? '.' : '#');
    }
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) ans.push_back(s), ans.push_back(s);
        else ans.push_back(t), ans.push_back(t);
    }
    for (auto &a : ans) {
        cout << a << endl;
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
