#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string ans = "oox";
    for (int i = 0; i < 7; i++) {
        ans += ans;
    }
    int n;
    cin >> n;
    cout << ans.substr(0, n) << endl;

    return 0;
}
