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
    int getDecimalValue(ListNode* head) {
        vector<int>arr;
        ListNode *x = head;
        while(x!= NULL){
            arr.push_back(x->val);
            x=x->next;
        }

        int n = arr.size();
        int ans =0;
        for(int i=n-1;i>=0;i--){
            if(arr[i]==1)
                ans =ans + pow(2,n-1-i);
        }

        return ans;
    }
};