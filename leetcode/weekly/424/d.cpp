class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();

        auto check = [&](int x) {
            vector<pair<int, int>> p;
            for (int i = 0; i < n; i++) {
                if (nums[i] == -1) {
                    if (i > 0 && i < n - 1 && nums[i - 1] != -1 && nums[i + 1] != -1) {
                        int l = max(nums[i - 1] - x, nums[i + 1] - x);
                        int r = min(nums[i + 1] + x, nums[i - 1] + x);
                        p.emplace_back(l, r);
                    } else if (i > 0 && nums[i - 1] != -1) {
                        p.emplace_back(nums[i - 1] - x, nums[i - 1] + x);
                    } else if (i < n - 1 && nums[i + 1] != -1) {
                        p.emplace_back(nums[i + 1] - x, nums[i + 1] + x);
                    }
                }
            }
            if (p.empty()) return true;
            sort(p.begin(), p.end(), [](auto &a, auto &b) {
                return a.second < b.second;
            });
            int X = p[0].second, Y = -1e9;
            for (int i = 0; i < p.size(); i++) {
                if (p[i].first > X) Y = max(Y, p[i].first);
            }
            for (auto [a, b] : p) {
                if (!((X >= a && X <= b) || (Y >= a && Y <= b))) {
                    return false;
                }
            }
            for (int i = 0, j = -1; i < n; i++) {
                if (nums[i] >= 0) {
                    auto v = [&]() {
                        if (j == -1 || j + 1 == i) return true;
                        if (
                            (abs(nums[j] - X) <= x && abs(nums[i] - X) <= x) ||
                            (abs(nums[j] - Y) <= x && abs(nums[i] - Y) <= x)
                        ) return true;
                        if (Y - X > x) return false;
                        return true;
                    };
                    if (!v()) return false;
                    j = i;
                }
            }
            return true;
        };

        int mx = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i] != -1 && nums[i - 1] != -1) mx = max(mx, abs(nums[i] - nums[i - 1]));
        }
        int l = mx, r = *max_element(nums.begin(), nums.end()) + 5;
        while (l < r) {
            int mid = (l + r) / 2;
            if (check(mid)) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};
