//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector x(2, vector<int>()), y(2, vector<int>());
    for (int i = 0; i < n; i++) {
        int X, Y;
        cin >> X >> Y;
        int t = (X + Y) % 2;
        x[t].push_back(X + Y);
        y[t].push_back(X - Y);
    }

    auto check = [&](vector<int> &a) {
        sort(a.begin(), a.end());
        ll ans = 0;
        for (int i = 1; i < a.size(); i++) {
            ans += 1ll * i * (a.size() - i) * (a[i] - a[i - 1]);
        }
        return ans;
    };

    cout << (check(x[0]) + check(x[1]) + check(y[0]) + check(y[1])) / 2 << endl;

    return 0;
}
