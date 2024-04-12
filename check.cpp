#include<bits/stdc++.h>
using namespace std;
#define ll long long 

void solve(){
     int n;cin>>n;
     int arr[n];
     for(int i=0;i<n;i++)cin>>arr[i];
     sort(arr,arr+n);
     ll ans=0;ll x=0;
     int p2=n-1;
     for(int i=0;i<p2;i++){
		if(x+arr[i]>arr[p2] && x>0){
		    arr[p2]-=x;ans++;
		    x=arr[p2];ans+=x;
		    p2--;
		    int wanted=arr[i]/2;
		       
		}
		 if(i<p2){
		  x+=arr[i];
		  ans+=arr[i];
	     }
	 }
	 cout<<ans<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc;cin>>tc;
    while(tc--)
    {
        solve();
    }
}
 
