#include<bits/stdc++.h>
using namespace std;

int nxt[100009];
char s[100009];
int dp[100009];
int n, ans[100009];

int main(){
	scanf("%s", s + 1);
	int len = strlen(s + 1);
	int k = nxt[1] = 0;
	for(int i = 2; i <= len; i++){
		while(k && s[k + 1] != s[i]){
			k = nxt[k];
		}
		if(s[k + 1] == s[i]) k++;
		nxt[i] = k;
	}
	for(int i = nxt[len]; i; i = nxt[i]) ans[++n] = i;
	for(int i = len; i >= 1; i--){
		dp[i]++;
		dp[nxt[i]] += dp[i];
	}
	printf("%d\n", n + 1);
	for(int i = n; i >= 1; i--){
		printf("%d %d\n", ans[i], dp[ans[i]]);
	}
	printf("%d %d", len, dp[len]);
}
