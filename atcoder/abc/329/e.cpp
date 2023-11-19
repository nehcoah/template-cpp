#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;

    auto check = [&](int p) {
        bool ok = false;
        for (int j = 0; j < m; j++) {
            if (s[j + p] != '#' && s[j + p] != t[j]) return false;
            if (s[j + p] == t[j]) ok = true;
        }
        return ok;
    };

    auto stamp = [&](int p) {
        for (int j = 0; j < m; j++) s[j + p] = '#';
    };

    queue<int> q;
    for (int i = 0; i <= n - m; i++) {
        if (check(i)) {
            q.push(i);
            stamp(i);
        }
    }
    while (!q.empty()) {
        int x = q.front(); q.pop();
        for (int i = max(0, x - m + 1); i < min(n - m + 1, x + m - 1); i++) {
            if (check(i)) {
                q.push(i);
                stamp(i);
            }
        }
    }
    if (s == string(n, '#')) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}


