#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod=1e9+7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    vector<int>dp(m,0);
    vector<char>dp1;
    for(int i=0;i<m;i++)
    {
        int x;
         char y;
        cin>>x;
        cin>>y;
        dp[i]=x;
        dp1.push_back(y);
    }
   
    map<int,int>mp;

    for(int i=0;i<m;i++)
    {
        if(mp.find(dp[i])==mp.end() && dp1[i]=='M')
        {   //cout<<dp[i]<<" "<<dp1[i]<<endl;
            cout<<"Yes"<<endl;
            mp[dp[i]]++;
        }
        else{
            // cout<<dp[i]<<" "<<dp1[i]<<endl;
            if(dp1[i]=='M'){
            mp[dp[i]]++;
            }
            cout<<"No"<<endl;
        }
    }
    
return 0;    
}
