/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *st1= headA;
        ListNode *st2=headB;
        vector<int>A,B;
        
        while(st1)
        {
            A.push_back(st1->val);
            st1=st1->next;
        }
        
        while(st2)
        {
            B.push_back(st2->val);
            st2=st2->next;
        }
        
        int i=A.size()-1,j=B.size()-1;
        while(i>0 && j>0)
        {
            if(A[i]==B[j] )
            {
                i--;j--;
            }
            else
                break;
        }
        
        st1=headA;
        st2=headB;
        while(i--)
        {
            st1=st1->next;
        }
        while(j--)
        {
            st2=st2->next;
        }
        
        while(st1 && st2)
        {
            if(st1==st2)
                return st1;
            else
            {
                st1=st1->next;
                st2=st2->next;
            }
        }
       
        return st1;
    }
};