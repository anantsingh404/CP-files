#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod=1e9+7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin>>t;
    while(t--)
    {
    int n;
    cin>>n;
     int k;
     cin>>k;

    vector<vector<char>>dp(n,vector<char>(n,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>dp[i][j];
        }
    } 

    vector<vector<char>>ans;
     for(int i=0;i<n;i+=k)
     {vector<char>temp;
      for(int j=0;j<n;j+=k)
      { 
        
        if(dp[i][j]=='0')
        {
            temp.push_back('0');
        }
        else{
            temp.push_back('1');
        }
      }
      for(int k=0;k<temp.size();k++)
      {
        cout<<temp[k];
      }
      cout<<endl;
     }
     
     
    
    }



    
    
    
   
return 0;    
}
