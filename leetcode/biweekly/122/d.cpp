class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n = nums.size();
        long long ans = numeric_limits<long long>::max(), cur = 0;
        multiset<int> l, r;
        
        auto add = [&](int x) {
            l.insert(x);
            cur += x;
            if (l.size() > k - 1) {
                cur -= *l.rbegin();
                r.insert(*l.rbegin());
                l.erase(--l.end());
            }
        };
        
        auto remove = [&](int x) {
            auto it = l.find(x);
            if (it != l.end()) {
                cur -= *it;
                l.erase(it);
                l.insert(*r.begin());
                cur += *r.begin();
                r.erase(r.begin());
            } else {
                r.erase(r.find(x));
            }
        };
        
        for (int i = 1; i <= dist + 1; i++) {
            add(nums[i]);
        }
        ans = min(ans, cur);
        for (int i = dist + 2; i < n; i++) {
            add(nums[i]);
            remove(nums[i - dist - 1]);
            ans = min(ans, cur);
        }
        return ans + nums[0];
    }
};
