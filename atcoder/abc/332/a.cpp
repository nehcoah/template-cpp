#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, s, k;
    cin >> n >> s >> k;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        int p, q;
        cin >> p >> q;
        sum += p * q;
    }
    cout << (sum < s ? sum + k : sum) << endl;

    return 0;
}

