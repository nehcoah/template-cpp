#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using ull = unsigned long long;
using u32 = unsigned;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<string> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    auto ans = a;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int x = i, y = j;
            for (int k = 0; k < (min({i, n - i - 1, j, n - 1 - j}) + 1) % 4; k++) {
                tie(x, y) = make_pair(y, n - 1 - x);
            }
            ans[x][y] = a[i][j];
        }
    }

    for (auto &s : ans) {
        cout << s << "\n";
    }


    return 0;
}

