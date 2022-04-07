// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
public:
    struct trieNode{
        vector<trieNode*> dict;
        bool isEnd;
    };
    
    trieNode* newtrieNode(){
        trieNode* t=new trieNode();
        t->dict = vector<trieNode*>(26,0);
        t->isEnd = false;
        return t;
    }
    
    trieNode *root = newtrieNode();
    
    void insert(string &s){
        trieNode *trav = root;
        for(int i=0;i<s.size();i++){
            if(trav->dict[s[i]-'a']==NULL){
                trav->dict[s[i]-'a'] = newtrieNode();
            }
            trav = trav->dict[s[i]-'a'];
        }
        trav->isEnd = true;
    }
    int preLen(){
        trieNode *trav =root;
        int len=0;
        while(trav){
            int count = 0;
            trieNode* next;
            for(int i=0;i<26;i++){
                if(trav->dict[i]!=NULL)
                {
                    count++;
                    next = trav->dict[i];
                }
                if(count>1) 
                    return len-1;
            }
            
            len++;
            trav = next;
            if(trav->isEnd==true)
                return len-1;
        }
        return 0;
    }
    
    string LCP(string ar[], int n)
    {
        for(int word=0;word<n;word++)
        {
            insert(ar[word]);
        }
        
        int res = preLen();
        if(res<0)
            return "-1";
            
        return ar[0].substr(0,res+1);
    }
};

// { Driver Code Starts.

int main() 
{

	int t;
	cin>>t;
	while(t--)
	    {
	        int n;
	        cin>>n;
	        string arr[n];
	        for(int i = 0;i<n;i++)
	            cin>>arr[i];
	        Solution ob;
	        cout<<ob.LCP(arr,n)<<endl;
	    }
	return 0;
}  // } Driver Code Ends