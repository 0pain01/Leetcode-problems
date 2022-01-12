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
    
    
    string linked(struct ListNode* head)
    {
        string x="";
        ListNode *temp=head;
        while(temp!=NULL)
        {
            x+=to_string(temp->val);
            temp=temp->next;
        }
        return x;
    }
    
    
    bool isPalindrome(ListNode* head) {
        string x = linked(head);
        string y (x.rbegin(),x.rend());
        
        if(x==y)
            return true;
        else 
            return false;
    }
};