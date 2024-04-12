#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long 
// this question is hard, but that only makes it worth to do.
// hope.
void solve(){
    ll i=1,j=2;vector<int>arr;arr.push_back(1);arr.push_back(2);
    while(j<1e9){
		arr.push_back(i+j);
		ll temp=i+j;
		i=j;j=temp;
	}
	for(int i=0;i<arr.size();i++)cout<<arr[i]<<" ";cout<<endl;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int tc;tc=1;
	while(tc--){
		solve();
	}
}
