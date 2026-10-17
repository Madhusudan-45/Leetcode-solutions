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
    ListNode* rotateRight(ListNode* head, int k) {

        // Step 1: Empty list ya single node
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        // Step 2: Length aur last node find karo
        int n = 1;
        ListNode* tail = head;

        while (tail->next != nullptr) {
            tail = tail->next;
            n++;
        }

        // Step 3: Extra rotations hata do
        int r = k % n;

        // Rotation ki zaroorat nahi
        if (r == 0) {
            return head;
        }

        // Step 4: Circular list banao
        tail->next = head;

        // Step 5: Naye tail tak pahucho
        int steps = n - r - 1;
        ListNode* newTail = head;

        for (int i = 0; i < steps; i++) {
            newTail = newTail->next;
        }

        // Step 6: Naya head set karo aur list kaato
        ListNode* newHead = newTail->next;
        newTail->next = nullptr;

        return newHead;
    }
};