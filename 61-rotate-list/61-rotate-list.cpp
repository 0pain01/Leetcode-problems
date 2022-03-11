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
    ListNode* rotateRight(ListNode* head, int k) {
        
        struct ListNode *temp = head;
        int size=0;
        if(temp==NULL)
            return head;
        while(temp->next!=NULL){
            temp=temp->next;
            size++;
        }
        
         cout<<size<<"-";
        if ( k ==0 || k==size+1 || k==2*(size+1) || size==0){
            return head;
        }
        else{
            struct ListNode *t = head;
            
            int l=size-(k%(size+1));
            cout<<l<<" ";
            
            while(l--){
                t=t->next;
            }
    
            
            temp->next=head;
            head=t->next;
            t->next=NULL;
            
            return head;
        }
        
    }
};