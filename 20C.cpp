#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,m;
struct Edge{
	int to,nxt,w;
}e[200009];
int head[100009],tot;
ll d[100009],l[100009];
bool vis[100009];

void add(int x,int y,int w){
	e[++tot].to=y;
	e[tot].w=w;
	e[tot].nxt=head[x];
	head[x]=tot;
}

void dij(int s){
	priority_queue<pair<int,int> > pq;
	for(int i=1;i<=n;i++) d[i]=9020809865732;
	d[s]=0;
	l[s]=-1;
	pq.push(make_pair(0,s));
	while(!pq.empty()){
		int x=pq.top().second;
		pq.pop();
		if(vis[x]) continue;
		vis[x]=1;
		for(int i=head[x];i;i=e[i].nxt){
			int y=e[i].to;
			if(d[y]>d[x]+e[i].w){
				d[y]=d[x]+e[i].w;
				l[y]=x;
				pq.push(make_pair(-d[y],y));
			}
		}
	}
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int x,y,w;
		scanf("%d%d%d",&x,&y,&w);
		if(x==y) continue;
		add(x,y,w),add(y,x,w);
	}
	dij(n);
	if(d[1]==9020809865732){
		cout<<-1;
		return 0;
	}
	for(int i=1;i!=-1;i=l[i]){
		cout<<i<<" ";
	}
	return 0;
}
