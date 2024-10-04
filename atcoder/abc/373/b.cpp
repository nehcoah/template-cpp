#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using ull = unsigned long long;
using u32 = unsigned;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    vector<int> idx(26);
    for (int i = 0; i < s.size(); i++) {
        char c = s[i];
        idx[c - 'A'] = i;
    }

    int ans = 0;
    for (int i = 0; i < 25; i++) {
        ans += abs(idx[i + 1] - idx[i]);
    }
    cout << ans << endl;

    return 0;
}

