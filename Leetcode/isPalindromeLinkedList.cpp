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
    bool isPalindrome(ListNode* head) {
        if (!head) 
            return true;

        ListNode* firstHalf = findHalfEnd(head);
        ListNode* secondHalfReversed = reverseLinkedList(firstHalf->next);
        ListNode* p1 = head;
        ListNode* p2 = secondHalfReversed;

        bool res = true;
        while (res && p2) {
            if (p1->val != p2->val) 
                res = false;
            p1 = p1->next;
            p2 = p2->next;
        }

        firstHalf->next = reverseLinkedList(secondHalfReversed);
        return res;
    }

    ListNode* findHalfEnd(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next != nullptr && fast->next->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }

        return slow;
    }

    ListNode* reverseLinkedList(ListNode *head) {
        ListNode* tempNext = nullptr;
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr != nullptr) {
            tempNext = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tempNext;
        }

        return prev;
    }
};
