#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int m = ceil(log2(n));
    cout << m << endl;
    vector<vector<int>> p(m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i >> j & 1) p[j].push_back(i);
        }
    }
    for (int i = 0; i < m; i++) {
        cout << p[i].size() << " ";
        for (int x : p[i]) {
            cout << x + 1 << " ";
        }
        cout << endl;
    }
    string s;
    cin >> s;
    int ans = 0;
    for (int i = 0; i < m; i++) {
        if (s[i] == '1') ans |= 1 << i;
    }
    cout << ans + 1 << endl;

    return 0;
}
