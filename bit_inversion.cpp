#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6;
string s;
int a[N],n;
void solve(){
	cin>>n;
	cin>>s;
	s=" "+s;
	for(int i=1;i<=n;i++){
		a[i]=a[i-1]+s[i]-'0';
	}
	for(int i=n;i>=1;i--){
		a[i-1]+=a[i]/10;
		a[i]%=10;
	}
	bool flag=1;
	for(int i=0;i<=n;i++){
		if(a[i]==0&&flag==1) continue;
		flag=0;
		cout<<a[i],a[i]=0;
	}
	puts("");
	return;
}
signed main(){
	int T;
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}
