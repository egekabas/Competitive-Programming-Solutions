#include<iostream>
#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
ll a[200100],t,ans;
void merge(int l,int r){
	if(l==r) return;
	int mid=(l+r)>>1;
	merge(l,mid),merge(mid+1,r);
	for(int i=l,j=mid+1;i<=mid;i++){
		while(j<=r&&a[j]-a[i]<t) j++;
		ans+=j-mid-1;
	}
	inplace_merge(a+l,a+mid+1,a+r+1);
}
int main(){
	int n;cin>>n>>t;
	for(int i=1;i<=n;++i) cin>>a[i],a[i]+=a[i-1];
	merge(0,n);cout<<ans;
}