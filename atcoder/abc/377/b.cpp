#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using ull = unsigned long long;
using u32 = unsigned;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<string> s(8);
    for (int i = 0; i < 8; i++) {
        cin >> s[i];
    }

    vector<int> row(8), col(8);
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (s[i][j] == '#') {
                row[i] = 1, col[j] = 1;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (row[i] == 0 && col[j] == 0) {
                ans += 1;
            }
        }
    }
    cout << ans << "\n";

    return 0;
}

