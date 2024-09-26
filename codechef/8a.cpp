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
    for(int i=0;i<n;i++)
    {
        cin>>dp[i];
        mp[dp[i]]++;
    }
    if(mp.size()==2)
    {  vector<int>flag;
        for(auto itr:mp)
        {
            flag.push_back(itr.first);
        }
        if(abs(flag[0]-flag[1])>=2)
        {
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    else{
        cout<<"NO"<<endl;
    }
    



    }
    


     return 0;    
}
