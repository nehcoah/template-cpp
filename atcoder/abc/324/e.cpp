#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    string t;
    cin >> n >> t;
    vector<string> s(n);
    for (int i = 0; i < n; i++) cin >> s[i];

    vector<int> pre(n), suf(n);
    for (int i = 0; i < n; i++) {
        int idx = 0;
        for (char c : s[i]) {
            if (c == t[idx]) idx++;
            if (idx == t.size()) break;
        }
        pre[i] = idx;
        idx = t.size() - 1;
        for (int j = s[i].size() - 1; j >= 0; j--) {
            if (s[i][j] == t[idx]) idx--;
            if (idx == -1) break;
        }
        suf[i] = idx;
    }
    ll ans = 0;
    sort(suf.begin(), suf.end());
    for (int i = 0; i < n; i++) {
        ans += lower_bound(suf.begin(), suf.end(), pre[i]) - suf.begin();
    }
    cout << ans << endl;


    return 0;
}

