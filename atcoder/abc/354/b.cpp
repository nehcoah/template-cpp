#include "bits/stdc++.h"

//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<pair<string, int>> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i].first >> s[i].second;
    }

    sort(s.begin(), s.end());
    int sum = accumulate(s.begin(), s.end(), 0, [&](auto a, auto &b) {
        return a + b.second;
    });
    cout << s[sum % n].first << endl;

    return 0;
}
