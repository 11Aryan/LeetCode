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
 
    ListNode* reverseKGroup(ListNode* head, int k) {   
        if(head==NULL)
        {return NULL;}
                                                     
        ListNode*prev=NULL;
        ListNode*cur=head;
        ListNode*forward=NULL;
        int count=0;
        int len=0;
        
        //agar reverse karne ke liye bache element kam h k ki value se to mat karo
        while(cur!=NULL)
        {
            cur=cur->next;
            len++;
        }
        cur=head;
        if(len<k)
            return cur;
        
        
        while(cur!=NULL && count<k)
        {
            forward=cur->next;
            cur->next=prev;
            prev=cur;
            cur=forward;
            count++;
        }
        //if(forward!=NULL)
        //
            head->next=reverseKGroup(forward,k);
        //
        
                                                    
         return prev;                                           
        
        
     }
};