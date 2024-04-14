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
    vector<int> cnt(26);
    for (char c : s) {
        cnt[c - 'a'] += 1;
    }
    map<int, int> mp;
    for (int x : cnt) if (x != 0) mp[x] += 1;
    for (auto [k, v] : mp) {
        if (v != 2) {
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";

    return 0;
}
