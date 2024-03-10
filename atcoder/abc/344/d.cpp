#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string t;
    int n;
    cin >> t >> n;
    vector<vector<string>> s(n);
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        s[i].resize(a);
        for (int j = 0; j < a; j++) {
            cin >> s[i][j];
        }
    }

    vector<int> dp(t.size() + 1, 1e9);
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        auto tmp = dp;
        for (int j = 0; j < s[i].size(); j++) {
            for (int x = t.size(); x >= s[i][j].size(); x--) {
                string cur = t.substr(x - s[i][j].size(), s[i][j].size());
                if (cur == s[i][j]) tmp[x] = min(tmp[x], dp[x - s[i][j].size()] + 1);
            }
        }
        dp.swap(tmp);
    }
    cout << (dp.back() == 1e9 ? -1 : dp.back()) << endl;

    return 0;
}
