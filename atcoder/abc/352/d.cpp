//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> p(n);
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        mp[p[i]] = i;
    }

    set<int> st;
    for (int i = 1; i <= k; i++) {
        st.insert(mp[i]);
    }
    int ans = *st.rbegin() - *st.begin();
    for (int i = k + 1; i <= n; i++) {
        st.insert(mp[i]);
        st.erase(mp[i - k]);
        ans = min(ans, *st.rbegin() - *st.begin());
    }
    cout << ans << endl;

    return 0;
}
