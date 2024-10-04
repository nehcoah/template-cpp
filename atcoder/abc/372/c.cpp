#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using ull = unsigned long long;
using u32 = unsigned;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    int cnt = 0;
    for (int i = 0; i < n - 2; i++) {
        if (s[i] == 'A' && s[i + 1] == 'B' && s[i + 2] == 'C') {
            cnt += 1;
        }
    }

    auto check = [&](int x) {
        int cur = 0;
        for (int i = max(0, x - 2); i <= min(n - 3, x); i++) {
            if (s[i] == 'A' && s[i + 1] == 'B' && s[i + 2] == 'C') {
                cur += 1;
            }
        }
        return cur;
    };

    while (q--) {
        int x;
        char c;
        cin >> x >> c;
        x -= 1;
        cnt -= check(x);
        s[x] = c;
        cnt += check(x);
        cout << cnt << "\n";
    }

    return 0;
}

