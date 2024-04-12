#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long 
bool cmp(pair<ll,ll>a,pair<ll,ll>b){
	return a.first<b.first;
}
int n;
vector<pair<ll,ll>>arr;
int search()
{
	
	  sort(arr.begin(),arr.end(),cmp);
    vector<pair<ll,ll>>suff(n,{0,INT_MAX}),prefix(n,{0,INT_MAX});
    prefix[0]={arr[0].second,arr[0].second};
    suff[n-1]={arr[n-1].second,arr[n-1].second};
    for(int i=1;i<n;i++){
	  prefix[i].first=max(prefix[i-1].first,arr[i].second);
	  prefix[i].second=min(prefix[i-1].second,arr[i].second);
	}
	for(int i=n-2;i>=0;i--){
	  suff[i].first=max(suff[i+1].first,arr[i].second);
	  suff[i].second=min(suff[i+1].second,arr[i].second);
    }
      ll ans=(arr[n-1].first-arr[0].first)*(suff[0].first-suff[0].second);
      ll temp=ans; 
    for(int i=1;i<n-1;i++){	
       ll first_area=(arr[i].first-arr[0].first)*(prefix[i].first-prefix[i].second);
       ll second_area=(arr[n-1].first-arr[i+1].first)*(suff[i+1].first-suff[i+1].second);
       if(arr[i+1].first!=arr[i].first || (arr[i].first==arr[i+1].first && (prefix[i].second>suff[i+1].first || prefix[i].first<suff[i+1].second))){
          ans=min(ans,first_area+second_area);	  
       }
	}
	return temp-ans;
}
void solve(){
	cin>>n;
	arr.resize(n);int ans=0;
   for(int i=0;i<n;i++){
	   int x,y;cin>>x>>y;
	   arr[i]={x,y};
   }
    ans=max(ans,search());
    for(int i=0;i<n;i++){
		swap(arr[i].first,arr[i].second);
	}
	ans=max(ans,search());
	cout<<ans<<endl;
}
int main(){
    freopen("split.in","r",stdin);
	freopen("split.out","w",stdout);
	int tc;tc=1;
	while(tc--){
		solve();
	}
}
 
