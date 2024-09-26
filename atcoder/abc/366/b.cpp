#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<string> a(n);
    int mx = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mx = max(mx, (int) a[i].size());
    }
    vector<string> ans;
    for (int i = 0; i < mx; i++) {
        ans.emplace_back();
        for (int j = n - 1; j >= 0; j--) {
            if (i < a[j].size()) ans.back() += a[j][i];
            else ans.back() += '*';
        }
        while (ans.back().back() == '*') ans.back().pop_back();
    }
    for (auto &s : ans) {
        cout << s << "\n";
    }

    return 0;
}

