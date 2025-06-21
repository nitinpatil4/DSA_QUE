class Solution {
public:

    // Function to reverse a linked list
    ListNode* reverse(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* forward = nullptr;

        while (curr != nullptr) {
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }

        return prev;
    }

    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return true;

        // Step 1: Find middle node
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse the second half
        ListNode* secondHalf = reverse(slow->next);
        slow->next = secondHalf;

        // Step 3: Compare both halves
        ListNode* p1 = head;
        ListNode* p2 = secondHalf;

        while (p2 != nullptr) {
            if (p1->val != p2->val)
                return false;

            p1 = p1->next;
            p2 = p2->next;
        }

        return true;
    }
};
