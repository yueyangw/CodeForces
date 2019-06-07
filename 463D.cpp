#include<bits/stdc++.h>
using namespace std;

int n,k,ans;
int pos[6][1009],a[6][1009];
int d[1009],pd[1009][1009],f[1009];
bool vis[1009];
vector<int> e[1009];


bool AssignMax(int* a,int b){
	if(*a < b){
		*a = b;
		return true;
	}
	else return false;
}

int dfs(int u) {
	if(f[u]!=-1) return f[u];
    f[u] = 0;
    for (int v : e[u]) f[u] = max(f[u], dfs(v));
    return ++f[u];
}

int main(){
	scanf("%d%d", &n, &k);
	memset (f,-1,sizeof(f));
	
	for(int i = 1; i <= k; i++){
		for(int j = 1; j <= n; j++){
			scanf("%d", &a[i][j]);
			pos[i][a[i][j]]=j;
		}
	}
	
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n; ++j){
			if(i == j) continue;
			pd[i][j] = true;
			for(int l = 1; l <= k; ++l){
				if(pos[l][i] > pos[l][j]){
					//printf("%d %d %d %d %d\n", l, i, j, pos[l][i], pos[l][j]);
					pd[i][j] = false;
					break;
				}
			}
			if(!pd[i][j]) continue;
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(i == j) continue;
			if(pd[i][j]) e[i].push_back(j);
		}
	}
	for(int i = 1; i <= n; i++){
		ans=max(ans,dfs(i));
	}
	printf("%d\n",ans);
	return 0;
}
