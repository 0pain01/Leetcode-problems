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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        vector <int> arr;
        
        struct ListNode *temp= l1;
        struct ListNode *temp1= l2;
        
        while(temp!=NULL){
            arr.push_back(temp->val);
            temp=temp->next;
        }
        while(temp1!=NULL){
            arr.push_back(temp1->val);
            temp1=temp1->next;        
        }
        
       sort(arr.begin(),arr.end());
        
       struct ListNode *head = NULL ;
        
       for (int i=0;i<arr.size();i++){
           struct ListNode *n ;
           struct ListNode *t = new ListNode();
           if (head==NULL){
               t->val = arr[i];
               t->next=NULL;
               head=t;
               n=head;
           }
           else{
               t->val=arr[i];
               t->next=NULL;
               n->next=t;
               n=t;
           }
       }
        
        return head;
        
    }
    
};