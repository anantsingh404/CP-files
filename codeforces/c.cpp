#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod=1e9+7;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //write your code here
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        ll m;
        ll k;
        cin>>n>>m>>k;
        vector<ll>dp(n,0);
        int j=0;
        for(int i=n;i>=1;i--)
        {
            dp[j]=i;
            ++j;
            if(j==n)
            {
                break;
            }
        }
        j=n-1;
        for(int i=m;i>=1;i--)
        {
            dp[j]=i;
            j--;
            if(j==0)
            {
                break;
            }
        }
        for(int i=0;i<n;i++)
        {
         cout<<dp[i]<<" ";
        }
        cout<<endl;
    }
    


     return 0;    
}
