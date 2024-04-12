#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long 
void solve(){
   int n;cin>>n;
   vector<pair<ll,ll>>arr(n);
   for(int i=0;i<n;i++){
	   int x,y;cin>>x>>y;
	   arr[i]={x,y};
   }
   sort(arr.begin(),arr.end());
   map<ll,ll>ysum;  
   map<ll,pair<ll,ll>>neg,pos;  
   for(int i=0;i<n;i++){
	   ysum[arr[i].first]+=abs(arr[i].second);
	   ysum[arr[i].first]%=mod;
   }ll ans=0;
   for(int i=0;i<n;i++){
	   if(arr[i].first<0){
		   neg[arr[i].second].first+=abs(arr[i].first);
		   neg[arr[i].second].second++;
	   }else{
		   pos[arr[i].second].first+=abs(arr[i].first);
		   pos[arr[i].second].second++;
	   }
   }map<int,int>count; 
   bool f=0;
   for(int i=0;i<n;i++){
	   ll height=ysum[arr[i].first];
	   if(f==0 &&arr[i].first>0){
		   f=1;count.clear();
	   }
	  if(arr[i].first<0){
        ll base=pos[arr[i].second].first+(pos[arr[i].second].second)*abs(arr[i].first);
        base+=(neg[arr[i].second].second-count)*abs(arr[i].first)+count[arr[i].second]*(arr[i].first)+neg[arr[i].second].first;
        ans+=(height)*(base);
        ans%=mod;
	  }else{
		ll base=neg[arr[i].second].first+(neg[arr[i].second].second)*abs(arr[i].first);
		base+=pos[arr[i].second]+count[arr[i].second]*(arr[i].first)+(pos[arr[i].second].second-count[arr[i].second])*(-arr[i].first);
		ans+=(height)*(base);
		ans%=mod;
	  }
	  count[arr[i].second]++;
   }
   cout<<ans<<endl;
}
int main(){	
	//freopen("triangles.in","r",stdin);
	//freopen("triangles.out","w",stdout);
	int tc;tc=1;
	while(tc--){
		solve();
	}
}
