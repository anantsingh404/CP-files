#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod=1e9+7;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //write your code here
   int t;
   cin>>t;
   while(t--)
   {
    int n;
    int k;
    cin>>n>>k;
    vector<int>dp(n,0);
    vector<int>bp(n,0);
    for(int i=0;i<n;i++)
    {
        cin>>dp[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>bp[i];
    }
    
   }

    


     return 0;    
}
