#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    deque<int> cnt(n);
    for (int i = 0; i < n; i++) {
        int c = 0;
        for (int j = 0; j < n; j++) {
            if (s[i][j] == '1') c++;
        }
        cnt[i] = c;
    }
    while (cnt.front() == 0) cnt.pop_front();
    while (cnt.back() == 0) cnt.pop_back();
    cout << (cnt.front() == cnt.back() ? "SQUARE" : "TRIANGLE") << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}

