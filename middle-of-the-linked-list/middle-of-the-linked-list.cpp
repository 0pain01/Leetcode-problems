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
    
    int size(ListNode *head){
        struct ListNode *temp=head;
        int cnt=0;
        
        while(temp!=NULL){
            temp=temp->next;
            cnt++;
        }
        return cnt;
    }
    
    ListNode* middleNode(ListNode* head) {
        int n = size(head);
        
        
            n=n/2+1;
            struct ListNode *temp = head,*prev=head;
            
            while(n--){
                prev=temp;
                temp=temp->next;
            }
            
            head=prev;
            return head;
        
    }
};