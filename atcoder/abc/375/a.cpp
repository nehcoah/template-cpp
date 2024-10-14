#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using ull = unsigned long long;
using u32 = unsigned;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    string s;
    cin >> n >> s;
    int ans = 0;
    for (int i = 1; i < n - 1; i++) {
        if (s.substr(i - 1, 3) == "#.#") {
            ans += 1;
        }
    }
    cout << ans << endl;

    return 0;
}

