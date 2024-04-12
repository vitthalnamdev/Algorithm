//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
   int vis[101][101];
   void dfs(vector<vector<int>>& image,int sr,int sc,int newcolor,int old){
       int n=image.size();int m=image[0].size();
       if(sr<0 || sc<0 || sr>=n || sc>=m )return;
       if(vis[sr][sc])return;
       vis[sr][sc]=1;
       if(image[sr][sc]!=old){
           return;
       }
       image[sr][sc]=newcolor;
       int arr[]={1,-1};
       for(int i=0;i<2;i++){
           //if(!vis[sr+arr[i]][sc])
           dfs(image,sr+arr[i],sc,newcolor,old);
           //if(!vis[sr][sc+arr[i]])
           dfs(image,sr,sc+arr[i],newcolor,old);
       }
   }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
       for(int i=0;i<=100;i++){
           for(int j=0;j<=100;j++)vis[i][j]=0;  
       }
       dfs(image,sr,sc,newColor,image[sr][sc]);
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
