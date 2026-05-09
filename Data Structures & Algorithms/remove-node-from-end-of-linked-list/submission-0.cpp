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
    void remove(ListNode* head,int n){
        if(!head)
            return;
        else if(n == 1){
            ListNode* nxt = head->next->next;
            ListNode* del = head->next;
            del->next = nullptr;
            head->next = nxt;
            return;
        }

        remove(head->next,n-1);
    }
    ListNode* reve(ListNode* prev,ListNode* curr){
        if(!curr)
            return prev;

        ListNode* nxt = curr->next;
        curr->next = prev;

        return reve(curr,nxt);
    }
    int len(ListNode* head){
        if(!head)
            return 0;

        return 1 + len(head->next);
    }
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        int lent = len(head);
        if(lent == 1)
            return nullptr;

        n = lent - n;
        remove(head,n);

        return head;
    }
};
