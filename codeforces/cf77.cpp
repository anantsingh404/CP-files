#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod=1e9+7;

long long int solve(long long int p, long long int q) {
    long long int  res = 1;
    while (q > 0) {
        
        if (q % 2 == 1) {

            res=(res*p)%mod;
        }
         p=pow(p,2)%mod;
        q=q/2;
    }
    return res;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //write your code here
    ll t;
    cin>>t;
    while(t--)
    {
      
    ll n;
    cin>>n;
        vector<ll>dp(n,0);
        ll sum = 0;
        ll ss = 0;
        for(int i=0;i<n;i++)
        {
            cin>>dp[i];
        }
        long long ans=0;
        for (int i = 0; i < n; ++i) {
           sum=(sum+dp[i])%mod;

           ss=(ss+(dp[i]*dp[i])%mod)%mod;
        }



        long long temp = (sum*sum-ss+mod)%mod;



        temp = (temp * solve(2, mod-2)) % mod;

        long long flag = temp;


        long long x = (1ll*(n)*(n-1)/2)%mod;


        long long xinv= solve(x,mod - 2);


        ans = (flag*xinv)%mod;
        cout << ans << endl;



    }
    


     return 0;    
}
