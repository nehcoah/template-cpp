#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; i++) cin >> s[i];
    vector<unordered_map<int, int>> mp(5);
    for (int i = 0; i < n; i++) {
        int cur = 0;
        for (char c : s[i]) cur += c - '0';
        mp[s[i].size() - 1][cur]++;
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        int cur = 0, tot = 0;
        for (char c : s[i]) tot += c - '0';
        for (int j = 0; j < s[i].size(); j++) {
            cur += s[i][j] - '0';
            if ((j + 1) * 2 < s[i].size()) ans += mp[s[i].size() - (j + 1) * 2 - 1][tot - 2 * cur];
            else if ((j + 1) * 2 > s[i].size()) ans += mp[(j + 1) * 2 - s[i].size() - 1][2 * cur - tot];
        }
    }
    cout << ans << endl;

    return 0;
}

