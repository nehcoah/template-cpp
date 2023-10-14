#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    string s;
    cin >> n >> s;

    vector<int> cnt(10);
    for (char c : s) cnt[c - '0']++;
    sort(s.begin(), s.end(), greater<>());
    ll mx = stol(s);
    vector<string> nums;
    for (ll i = 0; i * i <= mx; i++) {
        nums.emplace_back(to_string(i * i));
    }
    int ans = 0;
    for (auto &cur : nums) {
        auto curcnt = cnt;
        for (char c : cur) {
            curcnt[c - '0']--;
        }
        bool ok = true;
        for (int i = 1; i < 10; i++) {
            if (curcnt[i] != 0) {
                ok = false;
                break;
            }
        }
        ans += ok;
    }
    cout << ans << endl;

    return 0;
}

