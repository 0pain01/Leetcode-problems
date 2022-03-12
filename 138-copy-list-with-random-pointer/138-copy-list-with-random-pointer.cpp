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
        if(head==NULL)
            return head;
        Node* new_node = new Node(head->val);
        
        Node* thead = new_node;
        
        Node * temp = head->next;
        while(temp!=NULL)
        {
            Node *t1 = new Node(temp->val);
            thead->next=t1;
            temp=temp->next;
            thead=thead->next;
        }
        
        temp=head;
        thead=new_node;
        unordered_map<Node*,int>mp;
        int i=0;
        while(temp!=NULL)
        {
            mp[temp]=i;
            i++;
            temp=temp->next;
        }
        
        temp=head;
        while(temp!=NULL)
        {
            if(temp->random!=NULL)
            {
                int cnt= mp[temp->random];
                Node*t1=new_node;
                for(int i=0;i<cnt;i++)
                {
                    t1=t1->next;
                }
                thead->random=t1;
            } 
            temp=temp->next;
            thead=thead->next;
        }
        
        return new_node;
        
    }
};