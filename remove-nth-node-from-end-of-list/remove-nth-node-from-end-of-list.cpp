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
public:
    int size (ListNode *head)
    {
        struct ListNode *temp=head;
        int cnt=0;
        
        while(temp!=NULL)
        {
            temp=temp->next;
            cnt++;
        }
        return cnt;
    }
    
    
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
    
        
        if(head->next==NULL && n==1)
            return NULL;
    
        int l =  size(head)-n;
        
        struct ListNode *temp=head,*prev;
        if(l==0)
        {
            temp=temp->next;
            head=temp;
            return head;
        }
        
        while(l--){
            prev=temp;
            temp=temp->next;
        }
        prev->next=temp->next;
        
        return head;
    }
};