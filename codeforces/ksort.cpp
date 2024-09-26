#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //write your code here
    long long t;
    cin>>t;
    while(t--)
    {
        long long n;
        cin>>n;
        vector<long long>dp(n);
        for(long long i=0;i<n;i++)
        {
            cin>>dp[i];
        }
        vector<long long>dpp;
        for(long long i=1;i<n;i++)
        {
            
            if(dp[i]<dp[i-1]){
                dpp.push_back(abs(dp[i]-dp[i-1]));
            dp[i]=dp[i]+dpp.back();
            }
        }
        sort(dpp.begin(),dpp.end());
        
        long long sum=0;
        long long ans=0;
        long long m=dpp.size();
        long long i=0;
        while(i<m)
        {
            long long x=abs(sum-dpp[i]);
            sum+=x;
            ans+=x*((m-i)+1);
            while(i<m && dpp[i]-sum==0)
            {
               ++i;
            }
            

        }
        cout<<ans<<endl;


    }
    


return 0;    
}
