#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, a, b;
    cin >> n >> a >> b;
    map<int, ll> A, B;
    for (int i = 0; i < a; i++) {
        int id, v;
        cin >> id >> v;
        A[id] = v;
    }
    for (int i = 0; i < b; i++) {
        int id, v;
        cin >> id >> v;
        B[id] = v;
    }
    ll ans = 0;
    for (auto ita = A.begin(), itb = B.begin(); ita != A.end() && itb != B.end(); ) {
        if (ita->first < itb->first) ita++;
        else if (ita->first > itb->first) itb++;
        else {
            ans += ita->second * itb->second;
            ita++, itb++;
        }
    }
    cout << ans << endl;

    return 0;
}

