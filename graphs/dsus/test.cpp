#include<bits/stdc++.h>
using namespace std;
// it's all about findind ranks.
// it's all about finding friends.
// it's all about finding connections between two nodes, or two set connections.
class disjoint_set{
  public:
  int*rank,*parent;
  disjoint_set(int n){
	  rank= new int[n];
	  parent=new int[n];
	  for(int i=0;i<n;i++)rank[i]=0;
	  for(int i=0;i<n;i++)parent[i]=i;
  }
  int find(int a){
	  if(parent[a]==a){
		  return a;
	  }
	  return find(parent[a]);
  }
  void Union(int a,int b){
	  int x=find(a);
	  int y=find(b);
	  if(x==y)return;
	  if(rank[x]>rank[y]){
		  parent[y]=x;  
	  }else if(rank[x]<rank[y]){
		  parent[x]=y;
	  }else{
		  rank[x]++;
		  parent[y]=x;
	  }
  }
};
int main(){
	int n;cin>>n;int m;cin>>m;
	disjoint_set A(n);
	for(int i=0;i<m;i++){
		int a,b;cin>>a>>b;
		A.Union(a,b);
	}
	int q;cin>>q;
    while(q--){
	 int a,b;cin>>a>>b;
	 int x=A.find(a);int y=A.find(b);	
		if(x==y)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}
