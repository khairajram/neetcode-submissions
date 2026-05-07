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
public:
    ListNode* reverseList(ListNode* head) {
        if(!head)
            return head;
        return head = reve(nullptr,head);
    }
};
