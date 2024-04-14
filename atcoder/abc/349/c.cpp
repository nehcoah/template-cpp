// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s, t;
    cin >> s >> t;
    int i = 0, j = 0;
    for (; i < s.size() && j < 3; i++) {
        if (toupper(s[i]) == t[j]) j += 1;
    }
    if (j == 3) {
        cout << "Yes\n";
        return 0;
    }
    if (j == 2 && t.back() == 'X') {
        cout << "Yes\n";
        return 0;
    }
    cout << "No\n";

    return 0;
}
