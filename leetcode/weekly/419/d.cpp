class Solution {
public:
    vector<long long> findXSum(vector<int>& nums, int k, int X) {
        unordered_map<int, int> cnt;
        set<pair<int, int>> topk, other;
        vector<long long> ans;

        long long sum = 0;
        auto balance = [&]() {
            if (topk.size() > X) {
                while (topk.size() > X) {
                    auto [c, x] = *topk.begin();
                    topk.erase(topk.begin());
                    sum -= 1ll * c * x;
                    other.emplace(c, x);
                }
            }
            if (topk.size() < X) {
                while (topk.size() < X && !other.empty()) {
                    auto [c, x] = *other.rbegin();
                    other.erase(prev(other.end()));
                    sum += 1ll * c * x;
                    topk.emplace(c, x);
                }
            }
            while (!topk.empty() && !other.empty()) {
                auto [c1, x1] = *topk.begin();
                auto [c2, x2] = *other.rbegin();
                if (c1 < c2 || c1 == c2 && x1 < x2) {
                    sum -= 1ll * c1 * x1;
                    sum += 1ll * c2 * x2;
                    topk.erase(topk.begin());
                    other.erase(prev(other.end()));
                    topk.emplace(c2, x2);
                    other.emplace(c1, x1);
                } else {
                    break;
                }
            }
        };
        
        auto add = [&](int x) {
            int c = cnt[x];
            cnt[x] += 1;
            auto p = make_pair(c, x);
            if (topk.contains(p)) {
                topk.erase(p);
                sum -= 1ll * c * x;
            }
            if (other.contains(p)) other.erase(p);
            other.emplace(c + 1, x);
            balance();
        };

        auto del = [&](int x) {
            int c = cnt[x];
            cnt[x] -= 1;
            auto p = make_pair(c, x);
            if (topk.contains(p)) {
                topk.erase(p);
                sum -= 1ll * c * x;
            }
            if (other.contains(p)) other.erase(p);
            other.emplace(c - 1, x);
            balance();
        };

        for (int i = 0; i < k; i++) {
            add(nums[i]);
        }
        ans.push_back(sum);
        for (int i = k; i < nums.size(); i++) {
            add(nums[i]);
            del(nums[i - k]);
            ans.push_back(sum);
        }
        return ans;
    }
};
