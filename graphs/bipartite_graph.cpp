#include<bits/stdc++.h>
using namespace std;
 
class Solution {
public:
   int vis[100001];int color[100001];
   bool dfs(int node,int Color,vector<int>adj[]){	
       color[node]=Color;
       vis[node]=1;       
       for(auto i:adj[node]){
           if(!vis[i]){
            bool a=dfs(i,Color^1,adj);
            if(a==false)return false;
           }
           else if(Color==color[i]){               
               return false;
           }
       }
       return true; 
   }
	bool isBipartite(int V, vector<int>adj[]){
	    for(int i=0;i<=100000;i++)vis[i]=0,color[i]=0;
	    for(int i=0;i<V;i++){
	        if(!vis[i]){
	            bool ans=dfs(i,0,adj);
	            if(ans==false)return false;
	        }
	    }
	  
	    return true;
	}

};
 
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
 
