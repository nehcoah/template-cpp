// 2807
// https://leetcode.cn/problems/insert-greatest-common-divisors-in-linked-list/description/
// linkedlist, gcd

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        auto p = head;
        while (head->next) {
            int g = gcd(head->val, head->next->val);
            auto cur = new ListNode(g);
            auto d = head->next;
            head->next = cur; cur->next = d; head = d;
        }
        return p;
    }
};
