class Node{
public:
    Node *arr[26];
    bool isEnd=false;  
    string s="";
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
        temp->s=word;
    }
};
    
class Solution {
public:
    int n,m;
    int dx[4]={0,1,0,-1};
    int dy[4]={1,0,-1,0};
    vector<string> res; 
    void helper(vector<vector<char>>& board, vector<string> &words,int i, int j,Node *ptr)     {
  
        if(i<0 || j<0 || i>=n || j>=m || board[i][j]=='#')
            return;
        
        ptr=ptr->arr[board[i][j]-'a'];
        
        if(!ptr)
            return;
        
        if(ptr->isEnd)
        {
            ptr->isEnd=false;
            res.push_back(ptr->s);
        }
        
        char temp = board[i][j];
        board[i][j]='#';
        
        for(int k=0;k<4;k++)
        {
            helper(board,words,i+dx[k],j+dy[k],ptr);   
        }
        board[i][j]=temp;
        
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        n = board.size();
        m = board[0].size();
        int k = words.size();
        
        Trie obj;
        
        
            
        for(int x = 0 ;x<k ; x++)
        {
            obj.insert(words[x]);
        }

        for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                {
                    helper(board,words,i,j,obj.root);
                }
            }

        
        return res;
    }
};