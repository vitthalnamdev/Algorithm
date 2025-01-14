//{ Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

// } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int n, int m, string s1, string s2)
    {
       int dp[n+1][m+1];
       for(int i=0;i<=n;i++)for(int j=0;j<=m;j++)dp[i][j]=0;
       for(int i=0;i<n;i++){
           for(int j=0;j<m;j++){
               if(s1[i]==s2[j]){
                   dp[i+1][j+1]=max(dp[i+1][j+1],dp[i][j]+1);
               }else{
                   dp[i+1][j+1]=max(dp[i+1][j+1],dp[i+1][j]);
                   dp[i+1][j+1]=max(dp[i+1][j+1],dp[i][j+1]);
               }
           }
       }
       
       return dp[6][6];
    }
};


//{ Driver Code Starts.
int main()
{
    int t,n,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(n, m, s1, s2) << endl;
    }
    return 0;
}

// } Driver Code Ends
