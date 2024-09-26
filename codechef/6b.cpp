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
     int n;
     cin>>n;
     vector<int>dp(n,0);
     for(int i=0;i<n;i++)
     {
        cin>>dp[i];
     } 
for(int i=1;i<n;i++)
{
    cout<<dp[i]<<" ";
}
cout<<dp[0]<<endl;
    


    }
    


     return 0;    
}
