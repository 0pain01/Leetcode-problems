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
    ListNode* removeElements(ListNode* head, int val) {
        
       if(head==NULL || ((head->next==NULL) && (head->val!=val)))
            return head;
        
        struct ListNode *t = head;
        
        while(t!=NULL)
        {
            if(t->val==val)
            {
                t=t->next;
            }
            else
                break;
        }
        
        head=t;
        
        if(head==NULL || ((head->next==NULL) && (head->val!=val)))
            return head;
        
        struct ListNode *temp=head;
        
        while(temp->next!=NULL)
        {
            if(temp->next->val == val)
            {
                temp->next=temp->next->next;
            }
            else
            {
                temp=temp->next;
            }
        }
        
        if(head->val==val && head->next==NULL)
            return NULL;
            
        return head;
    }
};