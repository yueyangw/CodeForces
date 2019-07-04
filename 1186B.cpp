#include<bits/stdc++.h>
using namespace std;
int n,m;
int maxn,maxx;
int main(){
	scanf("%d%d", &n, &m);
	if(n%3==0){
		if(m%2==0) maxn=(m/2)*(n/3);
		else maxn=(m/2+1)*(n/3);
	}
	else if(n%3==1){
		if(m%2==0) maxn=(m/2)*(n/3)+m/3;
		else maxn=(m/2+1)*(n/3)+m/3;
	}
	else{
		if(m%2==0) maxn=(m/2)*(n/3+1);
		else maxn=(m/2+1)*(n/3+1);
	}
	swap(n,m);
	if(n%3==0){
		if(m%2==0) maxx=(m/2)*(n/3);
		else maxx=(m/2+1)*(n/3);
	}
	else if(n%3==1){
		if(m%2==0) maxx=(m/2)*(n/3)+m/3;
		else maxx=(m/2+1)*(n/3)+m/3;
	}
	else{
		if(m%2==0) maxx=(m/2)*(n/3+1);
		else maxx=(m/2+1)*(n/3+1);
	}
	printf("%d", max(maxn, maxx));
	return 0;
}
