#include "bits/stdc++.h"

using namespace std;
using ll = long long;
const int mod = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k;
    cin >> k;

    vector<ll> nums;
    string s;
    auto dfs = [&](auto self, int pre) {
        nums.push_back(stol(s));
        if (pre == 0) return;
        for (int i = 0; i < pre; i++) {
            s += char(i + '0');
            self(self, i);
            s.pop_back();
        }
    };
    for (int i = 1; i < 10; i++) {
        s = to_string(i);
        dfs(dfs, i);
    }
    std::sort(nums.begin(), nums.end());

    cout << nums[k - 1] << endl;

    return 0;
}
