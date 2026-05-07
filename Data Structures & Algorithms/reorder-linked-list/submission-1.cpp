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
    ListNode* reve(ListNode* prev,ListNode* curr){
        ListNode* nxt = curr->next;
        curr->next = prev;

        if(nxt)
            curr = reve(curr,nxt);

        return curr;
    }

    ListNode* hasCycle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* l2 = slow->next;
        slow->next = nullptr;

        return l2;
    }
public:
    void reorderList(ListNode* head) {
        if(!head || !head->next)
            return;
        ListNode* l1 = head;
        ListNode* l2 = hasCycle(head);

        l2 = reve(nullptr,l2);
        ListNode* temp = l1;

        while(temp && l2){
            ListNode* t1 = temp->next;
            ListNode* t2 = l2->next;
            temp->next = l2;
            l2->next = t1;
            l2 = t2;
            temp = t1;
        }
    }
};
