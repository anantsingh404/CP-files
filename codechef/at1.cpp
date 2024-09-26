#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod=1e9+7;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //write your code here
   
      
    ll n;
    cin>>n;
    int k;
    cin>>k;
    vector<int>dp(n,0);
    for(int i=0;i<n;i++)
    {
        cin>>dp[i];
    }
    while(k--)
    {
int x=dp.back();
dp.pop_back();
cout<<x<<" ";
    }
    for(int i=0;i<dp.size();i++)
    {
        cout<<dp[i]<<" ";
    }
    cout<<endl;
    



    
    

 
}
