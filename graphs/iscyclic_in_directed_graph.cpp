#include<bits/stdc++.h>
using namespace std;
map<int,int>vis,vis2;
map<int,list<int>>adj;
int ans=0;
void dfs(int node){
	vis[node]=true;vis2[node]=true;
	for(auto i:adj[node]){
		if(!vis[i])dfs(i);
		else if(vis2[i]){ans=1;return;}
	}
	vis2[node]=false;
}
int main(){
	int n,m;cin>>n>>m;
    for(int i=0;i<m;i++){
		int a,b;cin>>a>>b;
		adj[a].push_back(b);
	}	
    for(int i=0;i<n;i++){
		if(!vis[i])dfs(i);
	}
	if(ans)cout<<"cyclic"<<endl;
	else cout<<"Non cyclic"<<endl;
}
