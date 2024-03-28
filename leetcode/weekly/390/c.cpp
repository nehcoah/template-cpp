class Solution {
public:
    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {
        vector<long long> a(1e5 + 1);
        int n = nums.size();
        map<long long, set<long long>> mp;
        vector<long long> ans;
        for (int i = 0; i < n; i++) {
            int x = nums[i], f = freq[i];
            if (a[x] != 0) {
                mp[a[x]].erase(x);
                if (mp[a[x]].empty()) mp.erase(a[x]);
            }
            a[x] += f;
            if (a[x] != 0) mp[a[x]].insert(x);
            if (mp.empty()) ans.push_back(0);
            else ans.push_back(mp.rbegin()->first);
        }
        return ans;
    }
};
