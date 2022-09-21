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
    void mergeSort(ListNode** head)
    {
        ListNode* curr= *head;
        ListNode *a,*b;
        if(!curr or !curr->next) return;
        middle(curr,&a,&b);
        
        mergeSort(&a);
        mergeSort(&b);
        *head = merge(a,b);
        
    }
    
    void middle(ListNode *curr,ListNode** a,ListNode **b)
    {
        ListNode *fast,*slow;
        slow=curr;
        fast = curr->next;
        
        while(fast!=NULL)
        {
            fast=fast->next;
            if(fast!=NULL)
            {
                slow=slow->next;
                fast=fast->next;
            }
        }
        
        *a = curr;
        *b = slow->next;
        slow->next=NULL;
    }
    
    ListNode* merge(ListNode *a,ListNode *b)
    {
        ListNode *ans=NULL;
        
        if(!a) return b;
        else if(!b) return a;
        
        if(a->val<=b->val)
        {
            ans=a;
            ans->next = merge(a->next,b);
        }
        else
        {
            ans=b;
            ans->next = merge(a,b->next);
        }
        return ans;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if(n==0)
            return NULL;
        ListNode * temp=NULL;
        int i;
        for(i=0;i<n;i++)
        {
            if(lists[i]!=NULL)
            {
                temp=lists[i];
                break;
            }
        }
        ListNode *head=temp;
        
        for(int j=i+1;j<n;j++)
        {

            while(temp and temp->next!=NULL)
            {
                temp=temp->next;
            }
            if(lists[j])
            {temp->next=lists[j];
            temp=temp->next;}
        }
        
        mergeSort(&head);
        return head;
            
    }
};