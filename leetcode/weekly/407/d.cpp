struct Node {
    int l, r;
    Node(const int &_l, const int &_r): l(_l), r(_r) {}
    bool operator < (const Node &rhs) const {
        return l < rhs.l;
    }
};

class Solution {
public:
    long long minimumOperations(vector<int>& nums, vector<int>& target) {
        int n = nums.size();
        vector<int> t(n);
        for (int i = 0; i < n; i++) {
            t[i] = nums[i] - target[i];
        }
        
        auto check = [&](int l, int r) {
            set<Node> st;
            st.insert({l, r});
            map<int, vector<int>> mp;
            for (int i = l; i <= r; i++) {
                mp[abs(t[i])].push_back(i);
            }
            int pre = 0;
            long long ans = 0;
            for (auto &[k, v] : mp) {
                ans += 1ll * (k - pre) * st.size();
                pre = k;
                for (int p : v) {
                    auto it = st.upper_bound({p, -1});
                    assert(it != st.begin());
                    it = prev(it);
                    int nl = it->l, nr = it->r;
                    st.erase(it);
                    if (nl != p) st.insert({nl, p - 1});
                    if (nr != p) st.insert({p + 1, nr});
                }
            }
            return ans;
        };
        
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            if (t[i] != 0) {
                int j = i;
                while (j < n && 1ll * t[i] * t[j] > 0) j += 1;
                ans += check(i, j - 1);
                i = j - 1;
            }
        }
        return ans;
    }
};
