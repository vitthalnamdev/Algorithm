#include<bits/stdc++.h>
using namespace std;
map<int,list<int>>adj;
vector<int>visited(100001);
stack<int>temp;
void dfs(int v) {
    visited[v] = true;
    for (auto u : adj[v]){
        if (!visited[u])
           dfs(u);
    }
}
int main(){	
   int n;cin>>n;int m;cin>>m;
   for(int i=1;i<=m;i++){
	   int x,y;cin>>x>>y;
	   adj[x].push_back(y);
	   adj[y].push_back(x);
   }	 
}
