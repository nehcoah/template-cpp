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
    vector<int> s;
    for (int i = 0, a; i < n; i++) {
        cin >> a;
        while (!s.empty() && s.back() == a) {
            s.pop_back();
            a += 1;
        }
        s.push_back(a);
    }
    cout << s.size() << endl;

    return 0;
}
