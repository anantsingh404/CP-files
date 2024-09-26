#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MP make_pair
int main(){
	ios::sync_with_stdio(false);
	// freopen("Otomachi_Una.in","r",stdin);
	// freopen("Otomachi_Una.out","w",stdout);
	int _;cin>>_;
	while(_--){
		int n;cin>>n;
		for(int i=1;i<=n;i++) cout<<i<<" \n"[i==n];
	}
	return 0;
}