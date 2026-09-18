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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow = head;
        ListNode* fast = head;

    // move fast n steps ahead
        for(int i  = 0 ; i < n;i++){
            fast = fast->next;
        }
     // edge case: remove head
        if(fast == NULL){
            return head->next;
        }
    
     // move both
        while(fast->next != NULL){
            fast = fast->next;
            slow = slow->next;
        }

     // delete node
        slow->next = slow->next->next;

        return head;
    }
};