#include "bits/stdc++.h"

using namespace std;
using ll = long long;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b;
    cin >> a >> b;
    cout << int(pow(a, b) + pow(b, a)) << endl;

    return 0;
}
