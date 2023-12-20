#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    string s, t;
    cin >> s;
    if (ranges::is_sorted(s)) {
        cout << 0 << endl;
        return;
    }
    vector<int> idx;
    for (int i = 0; i < n; i++) {
        while (!idx.empty() && s[i] > s[idx.back()]) idx.pop_back();
        idx.push_back(i);
    }
    t = s;
    for (int i = 0; i < idx.size(); i++) {
        t[idx[i]] = s[idx[idx.size() - i - 1]];
    }
    if (ranges::is_sorted(t)) {
        int cnt = 0;
        for (int i = 1; i < idx.size(); i++) {
            if (s[idx[i]] == s[idx[i - 1]]) cnt++;
            else break;
        }
        cout << idx.size() - 1 - cnt << endl;
    } else {
        cout << -1 << endl;
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

