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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0);
        dummy.next = head;

        ListNode* groupPrev = &dummy;

        while (true) {
            // Find the kth node from groupPrev
            ListNode* kth = groupPrev;
            for (int i = 0; i < k && kth; ++i) {
                kth = kth->next;
            }

            // Fewer than k nodes remain
            if (!kth) break;

            ListNode* groupNext = kth->next;

            // Reverse current group
            ListNode* prev = groupNext;
            ListNode* curr = groupPrev->next;

            while (curr != groupNext) {
                ListNode* next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }

            // Connect reversed group with previous portion
            ListNode* oldGroupStart = groupPrev->next;
            groupPrev->next = kth;

            // oldGroupStart is now the end of this group
            groupPrev = oldGroupStart;
        }

        return dummy.next;
    }
};