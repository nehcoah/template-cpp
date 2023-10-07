#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (char c : s) if (c == 'o') a[i]++;
    }

    vector<int> idx(n);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int i, int j) {
        return a[i] == a[j] ? i < j : a[i] > a[j];
    });
    for (int i = 0; i < n; i++) cout << idx[i] + 1 << " \n"[i == n - 1];

    return 0;
}

