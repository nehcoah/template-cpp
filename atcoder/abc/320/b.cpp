#include "bits/stdc++.h"

using namespace std;
using ll = long long;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    auto check = [&](int i, int j) {
        for (; i < j; i++, j--) if (s[i] != s[j]) return false;
        return true;
    };

    int ans = 1;
    for (int i = 0; i < s.size(); i++) {
        for (int j = i + 1; j < s.size(); j++) {
            if (check(i, j)) ans = max(ans, j - i + 1);
        }
    }
    cout << ans << endl;
    return 0;
}
