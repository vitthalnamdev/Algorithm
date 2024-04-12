#include<bits/stdc++.h>
using namespace std;
map<int,list<int>>adj;
map<int,int>vis;
int parent[10000];
int dist[10000];
void bfs(int s){
queue<int>q;
q.push(s);
vis[s] = true;
parent[s] = -1;
while (!q.empty()) {
    int v = q.front();
    q.pop();
    for (int u : adj[v]) {
        if (!vis[u]) {
            vis[u] = true;
            q.push(u);
            dist[u] = dist[v] + 1;x`
            parent[u] = v;
        }
    }
}
	
}
vector<int> find_path(int v){
	vector<int>ans; 
	while(v!=-1){
		ans.push_back(v);v=parent[v];
	}reverse(ans.begin(),ans.end());
	return ans;
}
int main(){
	int n;cin>>n;int m;cin>>m;
	for(int i=1;i<=m;i++){
		int x,y;cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	int src=1;parent[src]=-1;
	bfs(src);
	// by the 40 line of code , we can get the imformation about the connected node. 
	// now dist array will store min distance to reach from src node to the ith node.
	// and parent array will store the current parent of the ith node if we start from src.
	vector<int>path;
	int v;cin>>v;
	if(!vis[v]){cout<<"No_Path"<<endl;}
	path=find_path(v);int x=path.size();
	for(int i=0;i<x;i++){cout<<path[i]<<" ";}cout<<endl;
}
/*
4 4
1 2
2 3
3 4
1 3



*/
