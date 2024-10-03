#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using ull = unsigned long long;
using u32 = unsigned;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < m; i++) {
        int A;
        char B;
        cin >> A >> B;
        A -= 1;
        if (B == 'M') {
            if (a[A] == 0) {
                cout << "Yes\n";
                a[A] = 1;
                continue;
            }
        }
        cout << "No\n";
    }

    return 0;
}

