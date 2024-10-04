#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using ull = unsigned long long;
using u32 = unsigned;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int mxa = -1e9, mxb = -1e9;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        mxa = max(mxa, a);
    }
    for (int i = 0; i < n; i++) {
        int b; cin >> b;
        mxb = max(mxb, b);
    }
    cout << mxa + mxb << endl;

    return 0;
}

