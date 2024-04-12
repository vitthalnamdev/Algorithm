#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long 
// this question is hard, but that only makes it worth to do.
// hope.
void solve(){
   int n;cin>>n;
   vector<vector<int>>north,east;
   for(int i=0;i<n;i++){
	   char dir;int x,y;cin>>dir>>x>>y;
	   if(dir=='N'){
		   north.push_back({x,y,i});
	   }else{east.push_back({x,y,i});}
   }
   sort(north.begin(),north.end(),[](vector<int>a,vector<int>b){return a[0]<b[0];});
   sort(east.begin(),east.end(),[](vector<int>a,vector<int>b){return a[1]<b[1];});
   vector<int>ans(n,0),stop(n,0);
   for(int i=0;i<east.size();i++){
	   for(int j=0;j<north.size();j++){
		   if(stop[east[i][2]]==0 && stop[north[j][2]]==0){
			   int xdis=north[j][0]-east[i][0];
			   int ydis=east[i][1]-north[j][1];
			   if(xdis>0 && xdis<ydis){
				  ans[east[i][2]]+=ans[north[j][2]]+1;
				  stop[north[j][2]]=1;  	
			   }else if(ydis>0 && ydis<xdis){
				    ans[north[j][2]]+=ans[east[i][2]]+1;
				    stop[east[i][2]]=1;  
			   }
	     }
	   }
   }
   for(int i=0;i<n;i++)cout<<ans[i]<<endl;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int tc;tc=1;
	while(tc--){
		solve();
	}
}
