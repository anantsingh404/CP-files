#include <bits/stdc++.h>
using namespace std;
int main() {
   int t;
   cin>>t;
   while(t--)
   {
    int n,k;
    cin>>n>>k;
    vector<int>dp(n,0);
    for(int i=0;i<n;i++)
    {
        cin>>dp[i];
    }
    int ans=INT_MIN;
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=dp[i];
        if(i>=k)
        {
            sum-=dp[i-k];
        }
        if(i>=k-1)
        {
          ans=max(ans,sum);
        }
    }
    cout<<ans<<endl;
   
   }
   
return 0;
}