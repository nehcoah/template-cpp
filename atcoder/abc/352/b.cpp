//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s, t;
    cin >> s >> t;

    for (int i = 0, j = 0; i < s.size(); i++) {
        while (s[i] != t[j]) j += 1;
        cout << j + 1 << " ";
        j += 1;
    }
    cout << endl;

    return 0;
}
