#include<bits/stdc++.h>
using namespace std;
map<string,int>check; 
void permutation(int i,string arr,int n){
	if(i==n)return;
	for(int j=i;j<n;j++){
	  swap(arr[i],arr[j]);
	  permutation(i+1,arr,n);
	  swap(arr[i],arr[j]);
	}
	if(check[arr]==1)return;
	check[arr]=1;
}
int main(){
	string arr;cin>>arr;
	int n=arr.length();
	permutation(0,arr,n);
    cout<<check.size()<<endl;
	for(auto i:check){
	  cout<<i.first<<endl;
	}cout<<endl;
}
