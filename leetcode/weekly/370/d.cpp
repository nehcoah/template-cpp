using ll = long long;
const ll inf = 1e16;

template<typename T>
struct Fenwick {
    int n;
    vector<T> tree;

    Fenwick(int n = 0) {
        init(n);
    }

    void init(int sz) {
        this->n = sz + 1;
        tree.assign(sz + 2, -inf);
    }

    void update(int pos, T val) {
        pos++;
        for (; pos < tree.size(); pos += pos & -pos) tree[pos] = max(tree[pos], val);
    }

    T query(int pos) {
        pos++;
        auto ans = -inf;
        for (; pos; pos -= pos & -pos) ans = max(ans, tree[pos]);
        return ans;
    }

};

class Solution {
public:
    long long maxBalancedSubsequenceSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> info;
        for (int i = 0; i < n; i++) info.push_back(nums[i] - i);
        ranges::sort(info);
        Fenwick<ll> t(n + 1);
        ll ans = -inf;
        for (int i = 0; i < n; i++) {
            int x = lower_bound(info.begin(), info.end(), nums[i] - i) - info.begin();
            ll cur = max(0LL, t.query(x)) + nums[i];
            t.update(x, cur);
            ans = max(ans, cur);
        }
        return ans;
    }
};
