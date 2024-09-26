#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod=1e9+7;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //write your code here
    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        ll k;
        cin>>n;
        cin>>k;
        vector<ll>dp(k,0);
        for(int i=0;i<k;i++)
        {
            cin>>dp[i];
        }
        sort(dp.begin(),dp.end());
        ll sum=0;
        for(int i=0;i<k-1;i++)
        {
            sum+=2*dp[i]-1;
        }
        cout<<sum<<endl;
    }
    


     return 0;    
}
