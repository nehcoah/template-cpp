// https://leetcode.cn/problems/buy-two-chocolates/

class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        sort(prices.begin(), prices.end());
        int x = money - prices[0] - prices[1];
        return x >= 0 ? x : money;
    }
};
