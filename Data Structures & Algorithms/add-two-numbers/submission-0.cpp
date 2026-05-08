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
    ListNode* reve(ListNode* prev, ListNode* curr){
        if(!curr)
            return prev;

        ListNode* nxt = curr->next;
        curr->next = prev;

        return reve(curr, nxt);
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // l1 = reve(nullptr,l1);
        // l2 = reve(nullptr,l2);
        
        int crr = 0;
        ListNode* head = new ListNode();
        ListNode* temp = head;

        while(l1 || l2 || crr){
            int sum = crr;
            
            if(l1){
                sum += l1->val;
                l1 = l1->next;
            }

            if(l2){
                sum += l2->val;
                l2 = l2->next;
            }
            
            crr = sum/10;

            temp->next = new ListNode(sum%10);
            temp = temp->next;
        }

           
        return head->next;
    }
};
