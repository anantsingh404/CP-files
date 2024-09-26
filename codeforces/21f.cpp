#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod=1e9+7;

string decrypt(string s,vector<string>ans,int m)
{   int n=s.size();
    vector<int>dp(m,0);
    int maxio=INT_MIN;
    int minio=INT_MAX;

    for(int i=0;i<m;i++)
    {  int count=0;
        for(auto itr:ans[i])
        {
        if(itr=='1')
          {
          ++count;
            }
        }
        dp[i]=count;
        maxio=max(maxio,dp[i]);
        minio=min(minio,dp[i]);

    }
    int count1=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='1')
        {
            count1;
        }
    }
    string ans="";
    int i=0;
    int x=n;
    int zero=n-count1;
    while(i<m)
    {
      
    }








   
}
int main()
{
    string s;
    cin>>s;
    int m;
    cin>>m;
    vector<string>ans(m);
    for(int i=0;i<m;i++)
    {
        cin>>ans[i];
    }
    decrypt(s,ans,m);


}