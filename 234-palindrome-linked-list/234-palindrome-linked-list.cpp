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
    bool palindrome(vector <int> arr)
    {
        int n=arr.size();
        int s=0,e=n-1;
        while(s<=e)
        {
            if(arr[s]!=arr[e])
                return 0;
            s++;e--;
        }
        return 1;
    }
    
    
    bool isPalindrome(ListNode* head) {
        vector <int> arr;
        ListNode*temp=head;
        while(temp!=NULL)
        {
            arr.push_back(temp->val);
            temp=temp->next;
        }
        return palindrome(arr);
    }
};