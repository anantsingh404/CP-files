#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod=1e9+7;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //write your code here
    int n;
    vector<int>dp(n,0);
    multiset<int>dp1;
    for(int i=0;i<n;i++)
    {
        cin>>dp[i];
    }
     for(int i=0;i<n-1;i++)
    {
        int x;
        cin>>x;
        dp1.insert(x);
    }
    sort(dp.begin(),dp.end());
    sort(dp1.begin(),dp1.end());
   // multiset<int>x;
   int count=0;
   int size=0;
    for(int i=n-1;i>=0;i--)
    {
        auto x=dp1.lower_bound(dp[i]);
        if(x!=dp1.end())
        {
          dp1.erase(x);
        }
        else{
            ++count;
            mini=dp[i];
        }
        if(count==2)
        {
            break;
        }
    }
    if(count==2)
    {
        cout<<-1<<endl;
    }
    else{
        cout<<mini<<endl;
    }

    


     return 0;    
}
