//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void loopHere(Node* head, Node* tail, int position)
{
    if(position==0) return;
    
    Node* walk = head;
    for(int i=1; i<position; i++)
        walk = walk->next;
    tail->next = walk;
}


// } Driver Code Ends
//User function Template for C++

/*struct Node
{
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }

*/
class Solution
{   
    Node*cycle(Node*head)
    {
         Node*slow=head;
        Node*fast=head;
        if(head==NULL||head->next==NULL)
        {
            return NULL;
        }
        while(fast)
        {
            fast=fast->next;
            if(fast)
            {
                fast=fast->next;
               
            slow=slow->next;
            }
            if(fast==slow)
             return slow;
        }
        return NULL;
        
    }
    public:
     //Function to find first node if the linked list has a loop.
    int findFirstNode(Node* head)
    {  
        Node*intersection=cycle(head);//floyd cycle detectionn
        Node*slow=head;
        if(intersection==NULL)   
         return -1;
        while(slow!=intersection) //starting point of loop
        {
            slow=slow->next;
            intersection=intersection->next;
        }
         return slow->data;
        // your code here
       
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, num;
        cin>>n;
        
        Node *head, *tail;
        cin>> num;
        head = tail = new Node(num);
        
        for(int i=0 ; i<n-1 ; i++)
        {
            cin>> num;
            tail->next = new Node(num);
            tail = tail->next;
        }
        
        int pos;
        cin>> pos;
        loopHere(head,tail,pos);
        
        Solution ob;
        int ans = ob.findFirstNode(head);
        cout<<ans<<"\n";
    }
	return 0;
}
// } Driver Code Ends