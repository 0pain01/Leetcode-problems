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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        struct ListNode *temp1 = l1;
        struct ListNode *temp2 = l2;
        int carry=0,sum=0;
        ListNode *p=NULL;
        ListNode *last = NULL;
        
        while(temp1 || temp2){
            sum = carry;
            if(temp1)
                {sum+=temp1->val;temp1=temp1->next;}
            if(temp2)
                {sum+=temp2->val;temp2=temp2->next;}
                    
            if (sum>9)
                carry=sum/10;
            else
                carry=0;
            
            sum=sum%10;
            
            struct ListNode *temp = new ListNode;
            if(p==NULL){
                temp->val=sum;
                temp->next=NULL;
                p=temp;
                last=temp;
            }
            else{
                temp->val=sum;
                temp->next=NULL;
                last->next=temp;
                last=temp;
            }
            
        }
        if(carry>0){
            struct ListNode *temp = new ListNode;
            temp->val=carry;
            temp->next=NULL;
            last->next=temp;
        }
        return p;
    }
};