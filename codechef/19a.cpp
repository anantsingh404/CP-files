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
        cin>>n;
        vector<int>dp(n,0);
        int maxi=0;
        unordered_map<ll,ll>mp;
        for(int i=0;i<n;i++)
        {
            cin>>dp[i];
            mp[dp[i]]++;
            maxi=max(dp[i],maxi);

        }
        sort(dp.begin(),dp.end());
        if(mp[maxi]==1)
        {
            cout<<"YES"<<endl;
        }
        else if(mp[maxi]%2==0)
        {
            int temp;
            bool flag=false;
            for(int i=n-1;i>=0;i--)
            {
                if(mp[dp[i]]%2==0)
                {
                    continue;
                }
                else{
                    flag=true;
                    break;
                }
            }
            if(flag)
            {
                cout<<"YES"<<endl;
            }
            else{
                cout<<"NO"<<endl;
            }
        }
        else{
            cout<<"YES"<<endl;
        }

    }


     return 0;    
}
