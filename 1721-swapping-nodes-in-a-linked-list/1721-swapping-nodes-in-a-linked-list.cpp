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
    int len(ListNode* head)
    {
        ListNode* temp=head;
        int size=0;
        
        while(temp)
        {
            temp=temp->next;
            size++;
        }
        
        return size;
    }
    
    ListNode* swapNodes(ListNode* head, int k) {
     
        
        int cnt=1;
        ListNode* temp = head;
        while(temp)
        {
            if(cnt==k)
                break;
            temp=temp->next;
            cnt++;
        }
        
        ListNode* temp1 = head;
        int n = len(head);
        cnt=1;
        while(temp1)
        {
            if(cnt==n-k+1)
                break;
            temp1=temp1->next;
            cnt++;
        }
        
        swap(temp->val,temp1->val);
    
        return head;
    }
};