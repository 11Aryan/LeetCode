//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
     struct Node* reverse(struct Node*head)
    {
        struct Node*cur=head;
        struct Node*prev=NULL;
        struct Node*forward=NULL;
        
        while(cur!=NULL)
        {
            forward=cur->next;
            cur->next=prev;
            prev=cur;
            cur=forward;
        }
        return prev;
        
        
    }
    void insertTail(struct Node* &head, struct Node* &tail,int data)
    {
        struct Node *temp= new Node(data);
        if(head==NULL){
            head=temp;
            tail=temp;
            return;    
        }
        else{
            tail->next=temp;
            tail=temp;
        }
          
        
    }
    struct Node* add(struct Node* l1, struct Node* l2)
    {
        int carry=0;
        struct Node* ansHead=NULL;
        struct Node* ansTail=NULL;
        while(l1!=NULL || l2!=NULL || carry!=0)
        {
            int v1=0;
            if(l1!=NULL)
                v1=l1->data;
            
            int v2=0;
            if(l2!=NULL)
                v2=l2->data;
            
            int sum=carry+v1+v2;
            int digit=sum%10;
            
            insertTail(ansHead,ansTail,digit);
            
            carry=sum/10;
            
            if(l1!=NULL)
                l1=l1->next;
            if(l2!=NULL)
                l2=l2->next;
                
        }
        return ansHead;
    }

    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here
        first=reverse(first);
        second=reverse(second);
        
        struct Node*ans=add(first,second);
        ans=reverse(ans);
        
        return ans;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends