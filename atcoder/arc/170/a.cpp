#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;

    vector<int> a, b;
    for (int i = 0; i < n; i++) {
        if (s[i] != t[i]) {
            if (s[i] == 'A') b.push_back(i);
            else a.push_back(i);
        }
    }

    int x = 0, y = 0, ans = 0;
    vector<int> left_b;
    for (; x < a.size() && y < b.size(); ) {
        if (a[x] < b[y]) {
            ans++, x++, y++;
        } else {
            left_b.push_back(b[y]);
            y++;
        }
    }
    while (y < b.size()) left_b.push_back(b[y++]);
    auto left_a = vector(a.begin() + x, a.end());

    if (!left_b.empty()) {
        for (int i = 0; i < n; i++) {
            if (i > left_b[0]) {
                cout << -1 << endl;
                return 0;
            }
            if (t[i] == 'A') {
                if (i < left_b[0]) ans += left_b.size();
                break;
            }
        }
    }
    if (!left_a.empty()) {
        for (int i = n - 1; i >= 0; i--) {
            if (i < left_a.back()) {
                cout << -1 << endl;
                return 0;
            }
            if (t[i] == 'B') {
                if (i > left_a.back()) ans += left_a.size();
                break;
            }
        }
    }
    cout << ans << endl;

    return 0;
}
