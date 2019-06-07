#include<bits/stdc++.h>
using namespace std;

int n;
int a[200009],f[200009],to[200009];
stack<int> st;

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		while(!st.empty()&&a[st.top()]>=a[i]){
			st.pop();
		}
		if(!st.empty()) to[i]=i-st.top();
		else to[i]=i;
		st.push(i);
	}
	st = stack<int>();
	for(int i=n;i>=1;i--){
		while(!st.empty()&&a[st.top()]>=a[i]){
			st.pop();
		}
		if(!st.empty()) to[i]+=st.top()-i-1;
		else to[i]+=n-i;
		st.push(i);
	}
	for(int i=1;i<=n;i++){
		f[to[i]]=max(f[to[i]],a[i]);
	}
	for(int i=n-1;i>=1;i--){
		f[i]=max(f[i],f[i+1]);
	}
	for(int i=1;i<=n;i++){
		printf("%d ",f[i]);
	}
	return 0;
}
