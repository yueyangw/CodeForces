#include<bits/stdc++.h>
using namespace std;

int n,m;
struct node{
	int v,l,r;
}tree[4000009];

int v[1000009],add[4000009];

void build(int k,int l,int r){
	if(l==r){
		tree[k].v=0;
		if(v[l]==1) tree[k].l=1;
		else tree[k].r=1;
		return;
	}
	int mid=(l+r)/2;
	build(k*2,l,mid);
	build(k*2+1,mid+1,r);
	int x=min(tree[k*2].l,tree[k*2+1].r);
	tree[k].v=(tree[k*2].v+tree[k*2+1].v+x);
	tree[k].l=(tree[k*2].l+tree[k*2+1].l-x);
	tree[k].r=(tree[k*2].r+tree[k*2+1].r-x);
	//printf("%d  %d to %d : %d个括号\n",k,l,r,tree[k].v);
}

node merge(int k,int l,int r,int x,int y){
	//printf("%d %d %d %d %d\n",k,l,r,x,y);
	node ans;
	ans.l=ans.r=ans.v=0;
	if(l>y||r<x) return ans;
	if(l>=x&&r<=y) return tree[k];
	int mid=(l+r)/2;
	if(x<=mid){
		node a=merge(k*2,l,mid,x,y);
		int x=min(ans.r,a.l);
		ans.v=ans.v+a.v+x;
		ans.l=ans.l+a.l-x;
		ans.r=ans.r+a.r-x;
	}
	if(y>mid){
		node b=merge(k*2+1,mid+1,r,x,y);
		int x=min(ans.l,b.r);
		ans.v=ans.v+b.v+x;
		ans.l=ans.l+b.l-x;
		ans.r=ans.r+b.r-x;
	}
	return ans;
}

int main(){
	string s;
	cin>>s;
	n=s.length();
	for(int i=1;i<=n;i++){
		if(s[i-1]=='(') v[i]=1;
		else v[i]=2;
	}
	build(1,1,n);
	printf("%d",merge(1,1,n,1,n).v*2);
	return 0;
}
