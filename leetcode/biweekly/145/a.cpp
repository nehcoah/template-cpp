class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        map<int, int> mp;
        for (int x : nums) {
            mp[x] += 1;
        }
        if (mp.begin()->first < k) return -1;
        return mp.size() - (mp.begin()->first == k);
    }
};
