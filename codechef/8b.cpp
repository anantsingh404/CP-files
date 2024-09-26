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
       int x,y,a,b;
       cin>>x>>y>>a>>b;
       vector<int>dp(200,0);
         int sum=0;
         int temp=min(y,b)-max(a,x);
        
       if(x<a)
       {
        dp[a-1]=1;
       }
       if(a<x)
       {
        dp[x-1]=1;
       }
       if(b>y)
       {
        dp[y]=1;
       }
       if(y>b)
       {
        dp[b]=1;
       }
       for(int i=0;i<200;i++)
       {
        sum+=dp[i];
       }
        if(temp<0)
         {
            sum=0;
         }
         int flag=max(0,min(y,b)-max(a,x));
         cout<<max(1,sum+flag)<<endl;

     

    }
    


     return 0;    
}
