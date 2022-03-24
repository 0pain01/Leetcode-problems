class Node{
public:
    Node *arr[26];
    bool isEnd=false;  
};

class Trie {
public:
    Node *root;
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node *temp =root;
        for(int i=0;i<word.size();i++)
        {
            if(!temp->arr[word[i]-'a'])
                temp->arr[word[i]-'a']= new Node();
            
            temp=temp->arr[word[i]-'a'];
        }
        temp->isEnd=true;
    }
    
    bool search(string word) {
        Node *temp =root;
        for(int i=0;i<word.size();i++)
        {
            if(!temp->arr[word[i]-'a'])
                return false;
            
            temp=temp->arr[word[i]-'a'];
        }
        return(temp->isEnd);
    }
    
    bool startsWith(string prefix) {
        Node *temp =root;
        for(int i=0;i<prefix.size();i++)
        {
            if(!temp->arr[prefix[i]-'a'])
                return false;
            
            temp=temp->arr[prefix[i]-'a'];
        }
        if(temp)
            return true;
        else 
            return false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */