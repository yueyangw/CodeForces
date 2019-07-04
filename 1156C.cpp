#include<bits/stdc++.h>
using namespace std;
 
int n, z;
int a[200009];
 
int main(){
	scanf("%d%d", &n, &z);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}
	sort(a + 1, a + n + 1);
	int ans = 1;
	for(int i = 1; i <= n; i++){
		if(a[i] - a[ans] >= z){
			ans++;
		}
	}
	printf("%d", min(n / 2, ans - 1));
	return 0;
}
