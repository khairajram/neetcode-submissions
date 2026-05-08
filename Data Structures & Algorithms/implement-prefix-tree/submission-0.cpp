class Node{
    public:
    bool isEnd;
    vector<Node*> next;    

    Node(){
        isEnd = false;
        next = vector<Node*>(26,nullptr);
    }
};

class PrefixTree {
    Node* head;

    void insertword(string w,Node* head,int i){
        if(i == w.size()){
            head->isEnd = true;
            return;
        }

        int idx = w[i] - 'a';

        if(!head->next[idx])
            head->next[idx] = new Node();
        
        insertword(w,head->next[idx],i+1);
    }

    bool searchword(string w,Node* head,int i){
        if(i == w.size())
            return head->isEnd;

        int idx = w[i] - 'a';

        if(!head->next[idx])
            return false;
        
        return searchword(w,head->next[idx],i+1);
    }

    bool startsWith(string w,Node* head,int i){
        if(i == w.size())
            return true;

        int idx = w[i] - 'a';

        if(!head->next[idx])
            return false;
        
        return startsWith(w,head->next[idx],i+1);
    }

public:
    PrefixTree() {
        head = new Node();
    }
    
    void insert(string word) {
        insertword(word,head,0);
    }
    
    bool search(string word) {
        return searchword(word,head,0);
    }
    
    bool startsWith(string prefix) {
        return startsWith(prefix,head,0);
    }
};
