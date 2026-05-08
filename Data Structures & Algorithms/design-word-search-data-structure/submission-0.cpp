class Node{
    public:
    bool isEnd;
    vector<Node*> next;    

    Node(){
        isEnd = false;
        next = vector<Node*>(26,nullptr);
    }
};

class WordDictionary {
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

        if(w[i] == '.'){
            bool ans = false;
            for(auto j : head->next){
                if(j)
                    ans |= searchword(w,j,i+1);
            }
            
        
            return ans;
        }

        int idx = w[i] - 'a';

        if(!head->next[idx])
            return false;
        
        return searchword(w,head->next[idx],i+1);
    }
public:
    WordDictionary() {
        head = new Node();
    }
    
    void addWord(string word) {
        insertword(word,head,0);
    }
    
    bool search(string word) {
        return searchword(word,head,0);
    }
};
