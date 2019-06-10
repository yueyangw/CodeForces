#include<bits/stdc++.h>
using namespace std;

int n,m;
int tree[400009],v[100009],tag[400009];
struct Que{
	int l,r,q;
}q[100009];

void add(int k,int l,int r,int val){
	tree[k]|=val;
	tag[k]|=val;
}

void pushdown(int k,int l,int r){
	tag[k*2]|=tag[k];
	tree[k*2]|=tag[k];
	tag[k*2+1]|=tag[k];
	tree[k*2+1]|=tag[k];
	tag[k]=0;
}

void modify(int k,int l,int r,int x,int y,int val){
	if(x<=l&&y>=r){
		add(k,l,r,val);
		return;
	}
	pushdown(k,l,r);
	int mid=(l+r)/2;
	if(mid>=x) modify(k*2,l,mid,x,y,val);
	if(mid<y) modify(k*2+1,mid+1,r,x,y,val);
	tree[k]=tree[k*2]&tree[k*2+1];
}

int query(int k,int l,int r,int x,int y){
	if(x<=l&&y>=r){
		return tree[k];
	}
	pushdown(k,l,r);
	int mid=(l+r)/2;
	int ans=(1<<30)-1;
	if(mid>=x) ans&=query(k*2,l,mid,x,y);
	if(mid<y) ans&=query(k*2+1,mid+1,r,x,y);
	return ans;
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&q[i].l,&q[i].r,&q[i].q);
		modify(1,1,n,q[i].l,q[i].r,q[i].q);
	}
	for(int i=1;i<=m;i++){
		if(query(1,1,n,q[i].l,q[i].r)!=q[i].q){
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	for(int i=1;i<=n;i++) printf("%d ",query(1,1,n,i,i));
	printf("\n");
	return 0;
}
