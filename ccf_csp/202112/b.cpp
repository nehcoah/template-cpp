#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, N;
    cin >> n >> N;
    vector<int> a(n + 1), b;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    a.push_back(N);
    int r = N / (n + 1);
    for (int i = 0; i * r < N; i++) {
        b.push_back(i * r);
    }
    b.push_back(N);

    ll ans = 0;
    for (int i = 0, j = 0; i < a.size() - 1 || j < b.size() - 1; ) {
        if (a[i] == b[j]) {
            ans += (min(a[i + 1], b[j + 1]) - a[i]) * abs(i - j);
            i++, j++;
        } else if (a[i] < b[j]) {
            ans += (min(a[i + 1], b[j]) - a[i]) * abs(j - i - 1);
            i++;
        } else {
            ans += (min(b[j + 1], a[i]) - b[j]) * abs(j + 1 - i);
            j++;
        }
    }
    cout << ans << endl;

    return 0;
}


