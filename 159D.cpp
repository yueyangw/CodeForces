#include<bits/stdc++.h>
using namespace std;

struct Solution{
	int len;
	string s;
	vector<int> start,end;
	vector<int> sum;
	long long ans;
	
	void dp(){
		/*for(int i=0;i<len;i++) f[i][i]=1;
		for(int st=2;st<=len;st++){
			for(int i=0;i+st-1<len;i++){
				int j=i+st-1;
				f[i][j]=f[i+1][j]+f[i][j-1]-f[i+1][j-1];
				if(s[i]==s[j]) f[i][j]+=f[i+1][j-1]+1;
			}
		}*/
		for(int i=0;i<len;i++){
			int l=i,r=i;
			for(;l>=0&&r<len;l--,r++){
				if(s[l]!=s[r]) break;
				start[l]++;
				end[r]++;
			}
		}
		for(int i=0;i<len-1;i++){
			int l=i,r=i+1;
			for(;l>=0&&r<len;l--,r++){
				if(s[l]!=s[r]) break;
				start[l]++;
				end[r]++;
			}
		}
	}
	
	void Solve(){
		cin>>s;
		len=s.length();
		start.resize(len);
		end.resize(len);
		sum.resize(len);
		dp();
		sum[0]=1;
		for(int i=1;i<len;i++) sum[i]=sum[i-1]+end[i];
		for(int i=1;i<len;i++) ans+=(long long)sum[i-1]*(long long)start[i];
		printf("%lld", ans);
	}
};

int main(){
	Solution().Solve();
	return 0;
}
