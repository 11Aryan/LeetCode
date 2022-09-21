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
   ListNode* solve(ListNode* list1, ListNode* list2)
    {  
       if(list1->next==NULL)
       {
           list1->next=list2;
           return list1;
       }
        ListNode*cur1=list1;
        ListNode*next1=cur1->next;
        ListNode*cur2=list2;
        ListNode*next2=cur2->next;
       
        
        while(next1!=NULL && cur2!=NULL)
        {
            if(cur2->val>=cur1->val && cur2->val<=next1->val)
            {
                cur1->next=cur2;
                next2=cur2->next;
                cur2->next=next1;
                
                cur1=cur2;
                cur2=next2;
                
            }
            else
            {
                cur1=next1;
                next1=next1->next;
                if(next1==NULL)
                {
                    cur1->next=cur2;
                    return list1;
                }
            }
        }
        return list1;
        }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL)
            return list2;
        if(list2==NULL)
            return list1;
        
        if(list1->val<=list2->val)
           return solve(list1,list2);
        else
           return solve(list2,list1);
      

       
    }
};