class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int sum = accumulate(apple.begin(), apple.end(), 0), cur = 0;
        sort(capacity.begin(), capacity.end(), greater<>());
        for (int i = 0; i < capacity.size(); i++) {
            cur += capacity[i];
            if (cur >= sum) return i + 1;
        }
        return 0;
    }
};
