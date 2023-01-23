//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define N 1000


// } Driver Code Ends
// you are required to complete this function 
// function should print the required range
class Solution{
    public:
    class node{
        public:
        int data;
        int row;
        int column;
        node(int d,int r,int c)
        {
            this->data=d;
            row=r;
            column=c;
        }
    };
    class compare{
        public:
        bool operator()(node*a,node*b)
        {
            return a->data>b->data;
        }
    };
    pair<int,int> findSmallestRange(int KSortedArray[][N], int n, int k)
    {
          //code here
          int mini;
          int maxi=INT_MIN;
          priority_queue<node*,vector<node*>,compare>m;
          for(int i=0;i<k;i++)
          {   
              maxi=max(maxi,KSortedArray[i][0]);
              m.push(new node(KSortedArray[i][0],i,0));
          }
          mini=m.top()->data;
          int start=mini;
          int end=maxi;
          while(m.size()>0)
          {   
              node*temp=m.top();
              m.pop();
              mini=temp->data;
              if(maxi-mini<end-start)
              {
                  start=mini;
                  end=maxi;
              }
              if(temp->column+1<n)
              {
                  maxi=max(maxi,KSortedArray[temp->row][temp->column+1]);
                  m.push(new node(KSortedArray[temp->row][temp->column+1],temp->row,temp->column+1));
              }
              else
              {
                  break;
              }
          }
          return{start,end};
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;
        int arr[N][N];
        pair<int,int> rangee;
        for(int i=0; i<k; i++)
            for(int j=0; j<n; j++)
                cin>>arr[i][j];
        Solution obj;
	    rangee = obj.findSmallestRange(arr, n, k);
	    cout<<rangee.first<<" "<<rangee.second<<"\n";
    }   
	return 0;
}


// } Driver Code Ends