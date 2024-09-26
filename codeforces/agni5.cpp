#include <bits/stdc++.h>
using namespace std;
int main() {
	// your code goes here
	long long int t;
	cin>>t;
	while(t--)
	{
	    long long int n;
	    cin>>n;
	    vector<long long int>dp(n);
	    long long int even=0;
	    long long int one=0;
	    for(int i=0;i<n;i++)
	    {
	        cin>>dp[i];
	        if(dp[i]==1)
	        {
	            ++one;
	        }
	    }
	    sort(dp.begin(),dp.end());
	    for(int i=0;i<n;i++)
	    {  
	        if(one==0)
	    {
	        break;
	    }
	        if(dp[i]%2==0)
	        {
	            dp[i]+=1;
	            --one;
	        }
	       // cout<<dp[i]<<" "<<endl;
	        
	    }
	    
	    long long int ans=1;
	    long long int mod=998244353;
	    for(long long int i=0;i<n;i++)
	    {   
	        ans=((ans%mod)*dp[i])%mod;
	    }
	    cout<<ans<<endl;
	    
	}

}
