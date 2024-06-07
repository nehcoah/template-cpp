#include "bits/stdc++.h"

//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;
using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    auto check = [&](string &S) {
        int p = 0, cnt = 0;
        char c = S[0];
        for (; p < n; p++) {
            if (S[p] != c) {
                if (cnt == k) c = S[p], cnt = 1;
                else {
                    p -= 1;
                    break;
                }
            } else {
                cnt += 1;
                if (cnt > k) break;
            }
        }
        return p;
    };

    auto p = check(s);
    if (p == n) {
        cout << n << endl;
        return;
    }
    int l = p, r = p;
    while (l >= 0 && s[l] == s[p]) l -= 1;
    while (r < n && s[r] == s[p]) r += 1;
    l += 1, r -= 1;
    string t;
    if (r - l + 1 <= k) {
        reverse(s.begin(), s.begin() + r + 1);
        t = s.substr(r + 1) + s.substr(0, r + 1);
        p = r;
    } else {
        reverse(s.begin(), s.begin() + r - k + 1);
        t = s.substr(r - k + 1) + s.substr(0, r - k + 1);
        p = r - k;
    }
    auto q = check(t);
    if (q == n) {
        cout << p + 1 << endl;
    } else {
        cout << -1 << endl;
    }
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

