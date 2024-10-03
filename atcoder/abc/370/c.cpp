#include "bits/stdc++.h"
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s, t;
    cin >> s >> t;

    vector<string> ans;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] - t[i] > 0) {
            s[i] = t[i];
            ans.push_back(s);
        }
    }
    for (int i = s.size() - 1; i >= 0; i--) {
        if (s[i] - t[i] < 0) {
            s[i] = t[i];
            ans.push_back(s);
        }
    }
    cout << ans.size() << "\n";
    for (auto &x : ans) {
        cout << x << "\n";
    }

    return 0;
}

