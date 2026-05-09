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
    ListNode* reverse(ListNode* head,int k){
        ListNode* prev = nullptr;
        ListNode* curr = head;
        
        while(k--){
            ListNode* nxt = curr->next;
            
            curr->next = prev;

            prev = curr;
            curr = nxt;
        }

        return prev;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr = head;
        int cnt = 0;

        while(cnt < k && curr){
            curr = curr->next;
            cnt++;
        }

        if(cnt < k)
            return head;

        ListNode* newHead = reverse(head,k);

        head->next = reverseKGroup(curr,k);

        return newHead;
    }
};
