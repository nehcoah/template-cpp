// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int x = stoi(s.substr(3));
    if (x < 350 && x != 316 && x != 0) cout << "Yes\n";
    else cout << "No\n";

    return 0;
}
