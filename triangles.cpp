#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long 
// this question is hard, but that only makes it worth to do.
// hope.
void solve(){
	int n;cin>>n;
	vector<pair<int,int>>arr(n);
	for(int i=0;i<n;i++)cin>>arr[i].first>>arr[i].second;
	vector<pair<int,int>>x[20002],y[20002];
	for(int i=0;i<n;i++){
		x[arr[i].first+10000].push_back({arr[i].second+10000,i});
		y[arr[i].second+10000].push_back({arr[i].first+10000,i});
	}
	vector<int>height(n,0),base(n,0);
	for(int i=0;i<=20000;i++){
		if(x[i].size()>0){
          ll curr=0;
          sort(x[i].begin(),x[i].end());
          for(int j=1;j<x[i].size();j++){
			  curr+=(x[i][j].first-x[i][0].first);
		  }  			
		  height[x[i][0].second]=curr;
		  for(int j=1;j<x[i].size();j++){
			  curr += (2 * j - x[i].size()) *
				        (x[i][j].first - x[i][j - 1].first);
			 height[x[i][j].second]=curr;
		  }
		}
			if(y[i].size()>0){
          ll curr=0;
          sort(y[i].begin(),y[i].end());
          for(int j=1;j<y[i].size();j++){
			  curr+=(y[i][j].first-y[i][0].first);
		  }  			
		  base[y[i][0].second]=curr;
		  for(int j=1;j<y[i].size();j++){
			  curr += (2 * j - y[i].size())*(y[i][j].first - y[i][j - 1].first);
			  base[y[i][j].second]=curr;
		  }
		}
	}
	ll ans=0;
	for(int i=0;i<n;i++){
		ans+=(height[i]*base[i]);
		ans%=mod;
	}cout<<ans<<endl;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	freopen("triangles.in","r",stdin);
	freopen("triangles.out","w",stdout);
	int tc;tc=1;
	while(tc--){
		solve();
	}
}
