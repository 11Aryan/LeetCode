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
    void deleteNode(ListNode* node) {
        ListNode *temp=node->next;
        node->val=temp->val;//agle node ka value copy kar dia isi node mein
        node->next=temp->next;//agli node ko point na kara ke uske baad wali ko point 
        delete(temp);
        
        
    }
};