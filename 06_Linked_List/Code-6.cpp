// Add Two Numbers
// https://leetcode.com/problems/add-two-numbers/

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode();
        ListNode* curr = dummy;
        int carry = 0;
        while (l1 || l2) {
            int val1 = (l1) ? l1->val : 0;
            int val2 = (l2) ? l2->val : 0;
            int sum = val1 + val2 + carry;
            carry = sum / 10;
            curr->next = new ListNode(sum % 10);
            curr = curr->next;
            if (l1) {
                l1 = l1->next;
            }
            if (l2) {
                l2 = l2->next;
            }
        }
        if (carry == 1) {
            curr->next = new ListNode(1);
        }
        return dummy->next;
    }