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
    vector<ll>dp(n,0);
    for(int i=0;i<n;i++)
    {
        cin>>dp[i];
    }
    string s;
    cin>>s;
    
    vector<ll>sum(n,0);
    sum[0]=dp[0];
    for(int i=1;i<n;i++)
    {
        sum[i]=dp[i]+sum[i-1];
    }
    queue<ll>left;
    stack<ll>right;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='L')
        {
            left.push(i);
        }
        if(s[i]=='R')
        {
            right.push(i);
        }
    }
    ll ans=0;
    while(!left.empty() && !right.empty() && left.front()<right.top())
    { 
        int a=left.front();
    int b=right.top();
    left.pop();
    right.pop();
    if(a-1>=0)
    {
        ans+=sum[b]-sum[a-1];
    }
else{
    ans+=sum[b];
}
    }
    cout<<ans<<endl;

    



    }
    


     return 0;    
}
