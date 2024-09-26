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
    unordered_map<int,int>mp;
    int maxi=1;
    for(int i=0;i<n;i++)
    {
        cin>>dp[i];
        mp[dp[i]]++;
        maxi=max(maxi,mp[dp[i]]);
    }
    cout<<n-maxi<<endl;
    



    }
    


     return 0;    
}
