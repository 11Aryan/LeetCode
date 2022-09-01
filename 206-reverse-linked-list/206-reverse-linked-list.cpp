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
    ListNode* reverseList(ListNode* head) {
        ListNode*cur=head;
        ListNode*prev=NULL;
        ListNode*forward=NULL ;
        if(head==NULL||head->next==NULL)
        {
            return head;
        }
        while(cur!=NULL)
        {
            forward=cur->next;
            cur->next=prev;
            prev=cur;
            cur=forward;
        }
     
        return prev;
    }
};