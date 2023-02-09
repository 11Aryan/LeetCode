//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        if(image[sr][sc]==newColor)
           return image;
        int r=image.size();
        int c=image[0].size();
        queue<pair<int,int>>q;
        q.push({sr,sc});
        int nrow,ncol;
        int cur=image[sr][sc];
        image[sr][sc]=newColor;

        while(!q.empty())
        {
            int row=q.front().first;
            int col=q.front().second;
            q.pop();

            //top
            nrow=row-1;
            ncol=col;
            if(nrow>=0&&nrow<r &&ncol>=0&&ncol<c &&image[nrow][ncol]==cur)
              {
                  q.push({nrow,ncol});
                  image[nrow][ncol]=newColor;
              }
            nrow=row+1;
            ncol=col;
            if(nrow>=0&&nrow<r&&ncol>=0&&ncol<c&&image[nrow][ncol]==cur)
               {
                  q.push({nrow,ncol});
                  image[nrow][ncol]=newColor;
              }
            nrow=row;
            ncol=col-1;
            if(nrow>=0&&nrow<r&&ncol>=0&&ncol<c&&image[nrow][ncol]==cur)
              {
                  q.push({nrow,ncol});
                  image[nrow][ncol]=newColor;
              } 
            nrow=row;
            ncol=col+1;
            if(nrow>=0&&nrow<r&&ncol>=0&&ncol<c&&image[nrow][ncol]==cur)
               {
                  q.push({nrow,ncol});
                  image[nrow][ncol]=newColor;
              }      
        }
            return image;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends