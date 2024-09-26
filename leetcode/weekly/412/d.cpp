class Solution {
public:
    int countPairs(vector<int>& nums) {
        unordered_map<int, int> mp;
        int ans = 0;
        for (int x : nums) {
            auto sx = to_string(x);
            sx = string(7 - sx.size(), '0') + sx;
            vector<int> cur{x};
            for (int i = 0; i < sx.size(); i++) {
                for (int j = i + 1; j < sx.size(); j++) {
                    swap(sx[i], sx[j]);
                    cur.push_back(stoi(sx));
                    auto sy = sx;
                    for (int p = 0; p < sy.size(); p++) {
                        for (int q = p + 1; q < sy.size(); q++) {
                            swap(sy[p], sy[q]);
                            cur.push_back(stoi(sy));
                            swap(sy[p], sy[q]);
                        }
                    }
                    swap(sx[i], sx[j]);
                }
            }
            sort(cur.begin(), cur.end());
            cur.erase(unique(cur.begin(), cur.end()), cur.end());
            for (int y : cur) {
                if (mp.count(y)) ans += mp[y];
            }
            mp[x] += 1;
        }
        return ans;
    }
};
