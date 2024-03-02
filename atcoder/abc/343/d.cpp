#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, t;
    cin >> n >> t;
    vector<ll> s(n);
    map<ll, ll> mp;
    mp[0] = n;

    while (t--) {
        int a, b;
        cin >> a >> b;
        a--;
        mp[s[a]] -= 1;
        if (mp[s[a]] == 0) mp.erase(s[a]);
        mp[s[a] + b] += 1;
        s[a] += b;
        cout << mp.size() << endl;
    }

    return 0;
}
