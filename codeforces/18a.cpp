#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod=1e9+7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    ll n,m;
    cin>>n>>m;

    int ans=0;
   for(int i=0;i<n;i++)
   { int count=0;
    for(int j=0;j<m;j++)
    {
      if(arr[i][j]%2)
      {
        ++count;
      }
    }
    if(count  && count%2==0)
    {
      ++ans;
    }
   }
   return ans;
return 0;    
}
