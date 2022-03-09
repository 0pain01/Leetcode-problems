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
    ListNode* deleteDuplicates(ListNode* head) {
        
        if(head==NULL || (head->next==NULL))
            return head;
        
        while(head!=NULL && head->next!=NULL && head->val==head->next->val)
        {
            int num=head->val;
            while(head->next!=NULL && head->next->val==num )
            {
                head=head->next;
            }
            head=head->next;
        }
        
        if(head==NULL)
            return head;
        
        struct ListNode *prev=head,*curr=head->next;
    
        while(curr!=NULL && curr->next!=NULL)
        {
            if(curr->val!=curr->next->val)
            {
                curr=curr->next;
                prev=prev->next;
            }
            else
            {
                cout<<curr->val<<" "<<curr->next->val<<endl;
                while(curr->next!=NULL && curr->val==curr->next->val)
                {
                    curr=curr->next;
                }
                
                prev->next=curr->next;
                curr=curr->next;
            }
        }

            
        return head;
    }
};