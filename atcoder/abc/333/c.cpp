#include "bits/stdc++.h"

using namespace std;
using ll = long long;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<ll> a{1};
    for (int i = 0; i < 12; i++) {
        a.push_back(a.back() * 10 + 1);
    }
    vector<ll> sum;
    for (int i = 0; i < 12; i++) {
        for (int j = i; j < 12; j++) {
            for (int k = j; k < 12; k++) {
                sum.push_back(a[i] + a[j] + a[k]);
            }
        }
    }
    ranges::sort(sum);
    cout << sum[n - 1] << endl;

    return 0;
}

