#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<int> cnt(n + 1);
    for (int i = 1; i < n; i++) {
        cnt[i + 1] = cnt[i] + (s[i] == s[i - 1]);
    }
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        cout << cnt[r] - cnt[l - 1] - ((l > 1 && s[l - 1] == s[l - 2]) ? 1 : 0) << "\n";
    }

    return 0;
}

