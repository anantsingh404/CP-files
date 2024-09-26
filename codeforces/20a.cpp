#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>p(n,0);
    for(int i=0;i<n;i++)
    {
       cin>>p[i];
    }
    vector<int>dp;
    for(int i=0;i<n;i+=2)
    {
        dp.push_back(p[i]-p[i+1]);
    }
    int ans=-1;
    int sum=0;
    int tmp=accumulate(dp.begin(),dp.end(),0);
    if(tmp<0)
    {
        cout<<-1;
        return 0;
    }
    for(int i=0;i<n;i++)
    {
        sum+=dp[i];
        if(sum<0)
        {
            ans=-1; 
            sum=0;
        }
        else if(sum>=0 && ans==-1)
        {
            ans=i; 
        }
    }
    cout<<ans;
    return 0;
}