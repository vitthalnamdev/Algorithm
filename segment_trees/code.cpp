#include<iostream>
using namespace std;
#define ll long long 
const int maxn=200001;
ll tree[4*maxn];
int arr[maxn];int m;
void build(int low,int high,int index){
   if(low==high){ tree[index]=arr[low]%m;return;}
   int mid=low+high>>1;
   build(low,mid,2*index+1);
   build(mid+1,high,2*index+2);
   tree[index]=(tree[2*index+1]+tree[2*index+2]);
}
ll query(int low,int high,int index,int l,int r){
	if(low>r || high<l)return 0;
	if(low>=l && high<=r)return tree[index];
	int mid=low+high>>1;
	int left=query(low,mid,2*index+1,l,r);
	int right=query(mid+1,high,2*index+2,l,r);
	return (left+right)%m;
}
int main(){
	 int n;cin>>n;
	 for(int i=0;i<n;++i)cin>>arr[i];
	 
}
