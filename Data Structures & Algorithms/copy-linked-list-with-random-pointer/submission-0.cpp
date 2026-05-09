/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* nHead = new Node(0);
        Node* temp = head;
        Node* temp2 = nHead;
        unordered_map<Node*,Node*> mp;

        while(temp){
            temp2->next = new Node(temp->val);

            temp2 = temp2->next;
            mp[temp] = temp2;
            temp = temp->next;
        }

        temp = head;
        temp2 = nHead->next;

        while(temp){
            if(!temp->random)
                continue;
            
            Node* n = mp[temp->random];

            temp2->random = n;

            temp2 = temp2->next;
            temp = temp->next;
        }

        return nHead->next;
    }
};
