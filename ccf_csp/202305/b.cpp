#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, d;
    cin >> n >> d;
    vector<vector<ll>> Q(n, vector<ll>(d)), K(d, vector<ll>(n)), V(n, vector<ll>(d));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < d; j++) {
            cin >> Q[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < d; j++) {
            cin >> K[j][i];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < d; j++) {
            cin >> V[i][j];
        }
    }

    vector<ll> W(n);
    for (int i = 0; i < n; i++) cin >> W[i];

    vector<vector<ll>> ans(n, vector<ll>(d));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ll cur = 0;
            for (int k = 0; k < d; k++) {
                cur += Q[i][k] * K[k][j];
            }
            for (int k = 0; k < d; k++) {
                ans[i][k] += W[i] * cur * V[j][k];
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < d; j++) {
            cout << ans[i][j] << " \n"[j == d - 1];
        }
    }

    return 0;
}


